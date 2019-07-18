#include "catch2/catch.hpp"

#include "states/states-manager.h"
#include "states/i-state.h"

SCENARIO("StateManager can push, pop and handle transition of Game states") {
	GIVEN("An empty StateManager") {
		entt::registry registry;
		StatesManager statesManager(registry);
		REQUIRE(statesManager.isEmpty() == true);

		WHEN("we push one state") {
			statesManager.push(STATE_TITLE_SCREEN);

			THEN("the manager should not be empty anymore") {
				REQUIRE(statesManager.isEmpty() == false);
			}
			THEN("the state pushed should be active") {
				auto state = statesManager.getActiveState();
				REQUIRE(state->getName() == STATE_TITLE_SCREEN);
			}
		}

		WHEN("we push multiple states") {
			statesManager.push(STATE_TITLE_SCREEN);
			auto state1 = statesManager.getActiveState();
			statesManager.push(STATE_LEVEL);
			auto state2 = statesManager.getActiveState();
		
			THEN("it should have exited the first state") {
				REQUIRE(state1->getLifeCycle() == StateLifeCycle::HAS_EXITED);
			}
			THEN("it should have entered the second state") {
				REQUIRE(state2->getLifeCycle() == StateLifeCycle::HAS_ENTERED);
			}
		}
	}

	GIVEN("A StateManager with only one state") {
		entt::registry registry;
		StatesManager statesManager(registry);
		statesManager.push(STATE_LEVEL);

		WHEN("we pop") {
			statesManager.pop();

			THEN("it should not pop") {
				REQUIRE(statesManager.isEmpty() == false);
			}
		}
	}

	GIVEN("A StateManager with multiple states") {
		entt::registry registry;
		StatesManager statesManager(registry);
		statesManager.push(STATE_TITLE_SCREEN);
		auto state1 = statesManager.getActiveState();
		statesManager.push(STATE_LEVEL);
		auto state2 = statesManager.getActiveState();

		WHEN("we pop") {
			statesManager.pop();
			
			THEN("it should have entered the first state") {
				REQUIRE(state1->getLifeCycle() == StateLifeCycle::HAS_ENTERED);
			}
			THEN("it should have exited the second state") {
				REQUIRE(state2->getLifeCycle() == StateLifeCycle::HAS_EXITED);
			}
		}
	}
}
