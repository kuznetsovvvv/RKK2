#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <State.h>



// Моки для различных состояний
class MockState : public State {
public:
  MOCK_METHOD0(insertCoin, void());
  MOCK_METHOD0(ejectQuarter, void());
  MOCK_METHOD0(turnCrank, void());
  MOCK_METHOD0(dispense, void());
};

TEST(StateTest, InsertCoin) {
  // Создание моки состояния
  MockState state;

  // Ожидание вызова метода insertCoin
  EXPECT_CALL(state, insertCoin()).Times(1);

  // Вызов метода insertCoin
  state.insertCoin();
}

TEST(StateTest, EjectQuarter) {
  // Создание моки состояния
  MockState state;

  // Ожидание вызова метода ejectQuarter
  EXPECT_CALL(state, ejectQuarter()).Times(1);

  // Вызов метода ejectQuarter
  state.ejectQuarter();
}

TEST(StateTest, TurnCrank) {
  // Создание моки состояния
  MockState state;

  // Ожидание вызова метода turnCrank
  EXPECT_CALL(state, turnCrank()).Times(1);

  // Вызов метода turnCrank
  state.turnCrank();
}
