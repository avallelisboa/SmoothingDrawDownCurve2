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
        accRef->isPlotting = false;

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
    if (ImGui::Button("Add")) {
        Admin::Get().AddR(theAccount.accountPt, theAccount.rToAdd);
        theAccount.rToAdd = 0;
        *p_open = false;
    }
    ImGui::End();
}
void GUIAdmin::graphicData(AccountRef& theAccount, bool* p_open)
{
    ImGuiWindowFlags flags = ImGuiWindowFlags_MenuBar;

    Account* p_account = theAccount.accountPt;
    std::list<Equity*> equitiesList = p_account->GetEquitiesList();
    std::list<Average*> movingaverage = p_account->GetMovingAverage();

    float (*plotequity)(void*, int) = &getEquity;
    float (*plotmovingaverage)(void*, int) = &getAverage;


    ImGui::Begin("Graphic data", p_open, flags);
    ImGui::PlotLines("Equity", plotequity, (void*)&equitiesList, equitiesList.size(), 0, NULL, 0.0f, 10.0f, ImVec2(0, 80.0f));
    ImGui::PlotLines("M.A 14", plotmovingaverage, (void*)&movingaverage, movingaverage.size(), 0, NULL, 0.0f, 10.0f, ImVec2(0, 80.0f));
    ImGui::End();
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
        graphicData(theAccount, &(theAccount.isPlotting));
        theAccount.isPlotting = true;
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
        const char* deleteCheckBoxLabel = "must delete?";
        size_t totalsize = strlen(accountName) + strlen(checkBoxLabel) + 1;
        char* checkBoxFullName = (char*)alloca(totalsize);
        memset(checkBoxFullName, 0, totalsize);
        strcat(checkBoxFullName, accountName);
        strcat(checkBoxFullName, checkBoxLabel);

        ImGui::Checkbox(checkBoxFullName, &(m_accountsReferences[count]->isOpen));
        ImGui::SameLine();
        ImGui::Checkbox("must delete?", &(m_accountsReferences[count]->mustBeDeleted));

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

        if ((*accrefIt)->isPlotting)
            graphicData(**accrefIt, &((*accrefIt)->isPlotting));

        accrefIt++;
    }
}