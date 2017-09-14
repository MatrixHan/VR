#include "deletescenenodecommand.h"
#include "../uimanager.h"
#include "../irisgl/src/scenegraph/scenenode.h"
#include "../mainwindow.h"
#include "../widgets/sceneheirarchywidget.h"

DeleteSceneNodeCommand::DeleteSceneNodeCommand(iris::SceneNodePtr parentNode, iris::SceneNodePtr sceneNode)
{
    this->parentNode = parentNode;
    this->sceneNode = sceneNode;
    this->position = parentNode->children.indexOf(sceneNode);
}

void DeleteSceneNodeCommand::undo()
{
    parentNode->insertChild(position, sceneNode, false);
    UiManager::sceneHeirarchyWidget->insertChild(sceneNode);
    UiManager::mainWindow->sceneNodeSelected(sceneNode);
}

void DeleteSceneNodeCommand::redo()
{
    UiManager::sceneHeirarchyWidget->removeChild(sceneNode);
    sceneNode->removeFromParent();// important that this is done after!
    UiManager::mainWindow->sceneNodeSelected(iris::SceneNodePtr());
}
