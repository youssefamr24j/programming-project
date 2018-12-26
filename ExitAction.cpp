#include "../Phase2 - Project Framework/ExitAction.h"
#include "../Phase2 - Project Framework/ApplicationManager.h"

#include "../Phase2 - Project Framework/GUI/Input.h"
#include "../Phase2 - Project Framework/GUI/Output.h"


ExitAction::ExitAction(ApplicationManager *pApp) : Action(pApp)
{}


void ExitAction::ReadActionParameters()
{}

//Execute action (Exit action)
void ExitAction::Execute()
{
	pManager->clearClipboard();
}
