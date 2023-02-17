#include <Geode/Geode.hpp>
#include <Geode/Modify.hpp>

USE_GEODE_NAMESPACE();

int cl = 0; // so it gets deleted when you're in your created levels

class $modify(EditLevelLayer) {
        bool init(GJGameLevel* ed) {
		    EditLevelLayer::init(ed);

			cl = 1;

        return true;
    }
};

class $modify(LevelInfoLayer) {
        bool init(GJGameLevel* ey) {
		    LevelInfoLayer::init(ey);

			cl = 0;

        return true;
    }
};

class $modify(MenuLayer) {
        bool init() {
		    MenuLayer::init();

			cl = 0;

        return true;
    }
};

class $modify(LevelTools) {
	static bool verifyLevelIntegrity(gd::string mg, int de) {
		return true;
	}
};

class $modify(PauseLayer) {
	static PauseLayer* create(bool ye) {
		auto create = PauseLayer::create(ye);
		PauseLayer* fcuk;

       	if (cl != 1) {
			/* auto lvls = LocalLevelManager::sharedState()->m_localLevels; */
			auto editorSprite = CCSprite::createWithSpriteFrameName("GJ_editBtn_001.png");
			auto menu = CCMenu::create();
			auto editorClick = CCMenuItemSpriteExtra::create(editorSprite, fcuk, menu_selector(PauseLayer::goEdit));
				menu->addChild(editorClick);
				menu->setPosition({22.750f, 92.5f});
				menu->setScale(0.768f);
				menu->setAnchorPoint({0.5f, 0.5f});
			create->addChild(menu, 0);
		}

		return create;
	}
};



