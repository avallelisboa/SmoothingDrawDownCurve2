#include "GUIAdmin.h"

GUIAdmin GUIAdmin::s_Instance;

GUIAdmin::GUIAdmin() {

}
GUIAdmin::~GUIAdmin()
{
    cleanUp();
}
void GUIAdmin::_makeAccountsReferences()
{
    m_accountsReferences.clear();
    auto accountIt = m_accounts.begin();
    size_t count = 0;
    while (accountIt != m_accounts.end()) {
        AccountRef* accRef  = new AccountRef();
        accRef->index = count;
        accRef->accountPt = (*accountIt);
        accRef->isOpen = false;
        accRef->mustBeDeleted = false;
        accRef->isAddingR = false;

        m_accountsReferences.push_back(accRef);

        accountIt++;
        count++;
    }
}
void GUIAdmin::_updateAccountsList() {
    m_accounts = Admin::Get().GetAccounts();
}
void GUIAdmin::_deleteSelectedAccounts()
{
    auto accountIt = m_accountsReferences.begin();
    while (accountIt != m_accountsReferences.end()) {
        auto accountRef = *accountIt;
        if (accountRef->mustBeDeleted) {
            Admin::Get().DeleteAccount(accountRef->accountPt);
        }
        accountIt++;
    }
    _loadData();
}
void GUIAdmin::_loadData()
{
    Admin::Get().LoadData();
    _updateAccountsList();
    _makeAccountsReferences();
}
void GUIAdmin::createAccount()
{
    auto result = Admin::Get().MakeAccount(m_accountToCreateName);
    m_wasError = !(result.wasCreated);
    m_errorMessage = result.errorMessage;
    _updateAccountsList();
    _makeAccountsReferences();
}
void GUIAdmin::showCreateAccountWindow()
{
    const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
    ImVec2 size = ImVec2(360, 240);
    ImGui::SetNextWindowPos(ImVec2((main_viewport->WorkPos.x + size.x) * 1.25f, main_viewport->WorkPos.y + size.y), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(size, ImGuiCond_FirstUseEver);
    ImGuiWindowFlags flags = ImGuiWindowFlags_MenuBar;
    ImGui::Begin("Create account", &m_mustShowCreateAccountWindow, flags);
    ImGui::Text("Create account");
    ImGui::Text("Enter the name of the account");
    ImGui::InputText(" ", m_accountToCreateName, sizeof(m_accountToCreateName));
    if (ImGui::Button("Create Account")) {
        createAccount();
        m_mustShowCreateAccountWindow = false;
    }
    if (ImGui::Button("Close"))
        m_mustShowCreateAccountWindow = false;

    ImGui::End();
}
void GUIAdmin::addOperation(AccountRef& theAccount, bool* p_open)
{
    ImGuiWindowFlags flags = ImGuiWindowFlags_MenuBar;
    ImGui::Begin("Add operation result", p_open, flags);
    ImGui::InputInt("Enter the operation result in r", &(theAccount.rToAdd));
    if (ImGui::Button("Add") && theAccount.rToAdd != 0) {
        Admin::Get().AddR(theAccount.accountPt, theAccount.rToAdd);
        theAccount.rToAdd = 0;
        *p_open = false;
    }
    ImGui::End();
}
void GUIAdmin::graphicData(AccountRef& theAccount)
{
    using namespace matplot;
    std::list<Equity*> equitiesList = theAccount.accountPt->GetEquitiesList();
    std::list<Average*> movingaverage = theAccount.accountPt->GetMovingAverage();

    std::vector<int> equities;
    std::vector<int> equitiesIndex;
    std::vector<double> ma;

    size_t size = equitiesList.size();

    equities.reserve(size);
    equitiesIndex.reserve(size);
    ma.reserve(size);

    auto equityit = equitiesList.begin();
    auto averageit = movingaverage.begin();
    while (equityit != equitiesList.end()) {
        equities.push_back((*equityit)->equity);
        equitiesIndex.push_back((*equityit)->index);

        ma.push_back((*averageit)->average);

        equityit++;
        averageit++;
    }

    auto p1 = plot(equitiesIndex, equities, "-");
    p1->display_name("Equities");
    p1->line_width(3.0f);
    hold(true);
    auto p2 = plot(equitiesIndex, ma, "-");
    p2->display_name("M.A.");
    p2->line_width(3.0f);

    title("Account Performance");
    xlabel("Operation Number");
    ylabel("Equity");

    hold(false);
    legend();
}
void GUIAdmin::closeAccount(AccountRef& theAccount)
{
    theAccount.isOpen = false;
}
void GUIAdmin::showOpenAccountWindow(AccountRef& theAccount, bool* p_open)
{
    const char* generalname = "Account: ";
    const char* accountname = theAccount.accountPt->Name();
    size_t totalsize = strlen(accountname) + strlen(generalname) + 1;
    char* fullname = (char*)alloca(totalsize);
    memset(fullname, 0, totalsize);
    strcat(fullname, generalname);
    strcat(fullname, accountname);

    ImGuiWindowFlags flags = ImGuiWindowFlags_MenuBar;

    ImGui::Begin(fullname, p_open, flags);
    auto aAccount = theAccount.accountPt;
    if (aAccount->IsThereEnoughData()) {
        if (aAccount->IsGhostMode())
            ImGui::Text("Ghost Mode");
        else
            ImGui::Text("Real Mode");
    }
    else
        ImGui::Text("There is not enough data");

    if (ImGui::Button("Add operation")) {
        theAccount.isAddingR = true;
        addOperation(theAccount, &(theAccount.isAddingR));
    }
    if (ImGui::Button("Graphic data") && theAccount.accountPt->IsThereEnoughData()) {
        graphicData(theAccount);
    }
    if (ImGui::Button("Close account"))
        closeAccount(theAccount);
    ImGui::End();
}
void GUIAdmin::showAccountsListWindow()
{
    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.    
    static float f = 0.0f;
    static int counter = 0;

    ImGui::Begin("Accounts");
    auto accountIt = m_accountsReferences.begin();
    size_t count = 0;
    while (accountIt != m_accountsReferences.end()) {
        const char* accountName = (*accountIt)->accountPt->Name();
        const char* checkBoxLabel = " is open?";
        const char* deleteCheckBoxLabel = " must delete?";
        size_t totalsize = strlen(accountName) + strlen(checkBoxLabel) + 1;
        size_t deleteCheckBoxTotalSize = strlen(accountName) + strlen(deleteCheckBoxLabel) + 1;
        char* checkBoxFullName = (char*)alloca(totalsize);
        char* deleteCheckBoxFullName = (char*)alloca(deleteCheckBoxTotalSize);
        memset(checkBoxFullName, 0, totalsize);
        memset(deleteCheckBoxFullName, 0, deleteCheckBoxTotalSize);
        strcat(checkBoxFullName, accountName);
        strcat(checkBoxFullName, checkBoxLabel);
        strcat(deleteCheckBoxFullName, accountName);
        strcat(deleteCheckBoxFullName, deleteCheckBoxLabel);

        ImGui::Checkbox(checkBoxFullName, &(m_accountsReferences[count]->isOpen));
        ImGui::SameLine();
        ImGui::Checkbox(deleteCheckBoxFullName, &(m_accountsReferences[count]->mustBeDeleted));

        accountIt++;
        count++;
    }
    if (ImGui::Button("Create Account"))  // Buttons return true when clicked (most widgets return true when edited/activated)
        m_mustShowCreateAccountWindow = true;

    if (ImGui::Button("Delete Selected Accounts"))
        _deleteSelectedAccounts();

    if (m_wasError)
        ImGui::Text(m_errorMessage.c_str());

    ImGui::End();
}
void GUIAdmin::cleanUp()
{
    auto accountreferencesIt = m_accountsReferences.begin();
    while (accountreferencesIt != m_accountsReferences.end()) {
        delete(*accountreferencesIt);
    }
}
void GUIAdmin::initApp()
{
    _loadData();
}
void GUIAdmin::showOpenAccountsWindows()
{
    auto accrefIt = m_accountsReferences.begin();
    while (accrefIt != m_accountsReferences.end()) {
        if ((*accrefIt)->isOpen)
            showOpenAccountWindow(**accrefIt, &((*accrefIt)->isOpen));
        if ((*accrefIt)->isAddingR)
            addOperation(**accrefIt, &((*accrefIt)->isAddingR));

        accrefIt++;
    }
}