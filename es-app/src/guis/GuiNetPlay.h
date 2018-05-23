//
// Created by xizor on 20/05/18.
//

#ifndef EMULATIONSTATION_ALL_GUINETPLAY_H
#define EMULATIONSTATION_ALL_GUINETPLAY_H

#include <components/ComponentList.h>
#include "GuiComponent.h"
#include "components/NinePatchComponent.h"
#include "components/ComponentGrid.h"
#include "resources/Font.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <recalbox/RecalboxSystem.h>

namespace json = boost::property_tree;

class TextComponent;
class ButtonComponent;

#define TITLE_VERT_PADDING (Renderer::getScreenHeight()*0.0637f)

class GuiNetPlay : public GuiComponent
{
public:
	GuiNetPlay(Window* window);

	void onSizeChanged() override;

	inline void addRow(const ComponentListRow& row, bool setCursorHere = false, bool updateGeometry = true) { mList->addRow(row, setCursorHere, updateGeometry); if (updateGeometry) updateSize(); }


	bool input(InputConfig* config, Input input) override;

	inline void clear() { mList->clear(); }

	std::vector<HelpPrompt> getHelpPrompts() override;

	bool parseLobby();

	void populateGridMeta(int i);

	void launch();

private:


	void updateSize();

	float getButtonGridHeight() const;

	NinePatchComponent mBackground;
	ComponentGrid mGrid;
	std::shared_ptr<ComponentGrid> mGridMeta;


	std::shared_ptr<TextComponent> mTitle;
	std::vector< std::shared_ptr<ButtonComponent> > mButtons;
	std::shared_ptr<ComponentGrid> mButtonGrid;
	std::shared_ptr<ComponentList> mList;

	std::vector<json::ptree::value_type> mRooms;

	std::shared_ptr<TextComponent> mMetaText;
};

#endif //EMULATIONSTATION_ALL_GUINETPLAY_H