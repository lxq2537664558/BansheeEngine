#include "DbgEditorWidget2.h"
#include "BsEditorWidgetManager.h"
#include "BsGUIToggle.h"
#include "BsGUIScrollArea.h"
#include "BsGUIArea.h"
#include "BsGUILayout.h"
#include "BsGUIWidget.h"
#include "BsGUISkin.h"
#include "BsGUIIntField.h"
#include "BsGUIFloatField.h"
#include "BsGUITextField.h"
#include "BsGUIVector2Field.h"
#include "BsGUIVector3Field.h"
#include "BsGUIVector4Field.h"
#include "BsGUIToggleField.h"
#include "BsGUIColorField.h"
#include "BsGUIGameObjectField.h"
#include "BsGUIButton.h"
#include "BsGUIFoldout.h"
#include "BsGUISpace.h"
#include "CmHString.h"

using namespace CamelotFramework;
using namespace BansheeEngine;

namespace BansheeEditor
{
	DbgEditorWidget2* DbgEditorWidget2::Instance = nullptr;

	DbgEditorWidget2::DbgEditorWidget2(const ConstructPrivately& dummy, EditorWidgetContainer& parentContainer)
		:EditorWidget<DbgEditorWidget2>(HString(L"DbgEditorWidget2"), parentContainer)
	{
		GUILayout& layout = mContent->getLayout().addLayoutY();

		GUIIntField* intField = GUIIntField::create(getParentWidget(), GUIContent(HString(L"Int Field")), 100, GUIOptions(GUIOption::fixedWidth(200)));
		GUIFloatField* floatField = GUIFloatField::create(getParentWidget(), HString(L"Float Field"), GUIOptions(GUIOption::fixedWidth(200)));
		GUITextField* textField = GUITextField::create(getParentWidget(), HString(L"Text Field"), GUIOptions(GUIOption::fixedWidth(200)));
		GUIVector4Field* vec4Field = GUIVector4Field::create(getParentWidget(), HString(L"Vec4 Field"), GUIOptions(GUIOption::fixedWidth(200)));
		GUIVector3Field* vec3Field = GUIVector3Field::create(getParentWidget(), HString(L"Vec3 Field"), GUIOptions(GUIOption::fixedWidth(200)));
		GUIVector2Field* vec2Field = GUIVector2Field::create(getParentWidget(), HString(L"Vec2 Field"), GUIOptions(GUIOption::fixedWidth(200)));
		GUIToggleField* toggleField = GUIToggleField::create(getParentWidget(), HString(L"Toggle Field"), GUIOptions(GUIOption::fixedWidth(200)));
		GUIColorField* colorField = GUIColorField::create(getParentWidget(), HString(L"Color Field"), GUIOptions(GUIOption::fixedWidth(200)));
		GUIFoldout* foldout = GUIFoldout::create(getParentWidget(), GUIOptions(GUIOption::fixedWidth(200)));
		GUIGameObjectField* gameObjectField = GUIGameObjectField::create(getParentWidget(), HString(L"Object Field"), GUIOptions(GUIOption::fixedWidth(200)));
		colorField->setValue(Color::Red);

		GUIButton* button = GUIButton::create(getParentWidget(), HString(L"Testing"), GUIOptions(GUIOption::fixedWidth(100)));

		layout.addElement(intField);
		layout.addElement(floatField);
		layout.addElement(textField);
		layout.addElement(vec4Field);
		layout.addElement(vec3Field);
		layout.addElement(vec2Field);
		layout.addElement(toggleField);
		layout.addElement(colorField);
		layout.addElement(foldout);
		layout.addElement(button);
		layout.addElement(gameObjectField);

		layout.addFlexibleSpace();
	}

	DbgEditorWidget2::~DbgEditorWidget2()
	{

	}

	DbgEditorWidget2* DbgEditorWidget2::instance()
	{
		return Instance;
	}

	DbgEditorWidget2* DbgEditorWidget2::open()
	{
		return static_cast<DbgEditorWidget2*>(EditorWidgetManager::instance().open(getTypeName()));
	}

	void DbgEditorWidget2::close()
	{
		if(Instance != nullptr)
			EditorWidgetManager::instance().close(Instance);

		Instance = nullptr; 
	}

	const String& DbgEditorWidget2::getTypeName()
	{
		static String name = "DbgEditorWidget2";
		return name;
	}
}