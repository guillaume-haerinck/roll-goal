#include <gtest/gtest.h>

#include "states/states-manager.h"
#include "states/i-state.h"

class StatesManagerSpec : public testing::Test {
	public:
		StatesManager statesManager;
};

TEST_F(StatesManagerSpec, IsEmpty) {
	EXPECT_EQ(statesManager.isEmpty(), true);
	statesManager.push(GameState::LEVEL);
	EXPECT_EQ(statesManager.isEmpty(), false);
}

TEST_F(StatesManagerSpec, Push_LastPushShouldBeActiveState) {
	statesManager.push(GameState::LEVEL);
	auto oldState = statesManager.getActiveState();
	ASSERT_FALSE(oldState == nullptr);
	EXPECT_EQ(oldState->getName(), GameState::LEVEL);

	statesManager.push(GameState::TITLE_SCREEN);
	auto newState = statesManager.getActiveState();
	ASSERT_FALSE(newState == nullptr);
	EXPECT_EQ(newState->getName(), GameState::TITLE_SCREEN);
}

TEST_F(StatesManagerSpec, Push_ShouldTriggerOnExitOnEnter) {
	statesManager.push(GameState::TITLE_SCREEN);
	auto oldState = statesManager.getActiveState();
	EXPECT_EQ(oldState->getLifeCycle(), LifeCycle::HAS_ENTERED);

	statesManager.push(GameState::LEVEL);

	auto newState = statesManager.getActiveState();
	EXPECT_EQ(oldState->getLifeCycle(), LifeCycle::HAS_EXITED);
	EXPECT_EQ(newState->getLifeCycle(), LifeCycle::HAS_ENTERED);
}

TEST_F(StatesManagerSpec, Pop_ShouldTriggerOnExitOnEnter) {
	statesManager.push(GameState::TITLE_SCREEN);
	auto oldState = statesManager.getActiveState();
	statesManager.push(GameState::LEVEL);
	auto newState = statesManager.getActiveState();

	statesManager.pop();

	EXPECT_EQ(oldState->getLifeCycle(), LifeCycle::HAS_ENTERED);
	EXPECT_EQ(newState->getLifeCycle(), LifeCycle::HAS_EXITED);
}

TEST_F(StatesManagerSpec, Pop_ShouldNotPopIfOnlyOneState) {
	statesManager.push(GameState::LEVEL);
	statesManager.pop();
	EXPECT_EQ(statesManager.isEmpty(), false);
}
