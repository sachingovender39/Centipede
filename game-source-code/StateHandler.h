#ifndef STATEHANDLER_H
#define STATEHANDLER_H

#include <memory>
#include <stack>
#include "GameState.h"

namespace GameEngine
{
class StateHandler
{
   public:
    /**
     * @brief Track whether a state is to be added. Assume that the
     * state to be added is replacing the state at the top of the stack.
     * @param newState Unique pointer to a new GameState object (instance).
     * @param replacing True if the state being added is replacing the
     * current state, False if the state being added is being pushed on
     * the stack.
     */
    void AddState(StatePtr newState, bool replacing = true);
    /**
     * @brief Pops the top state off the top of the stack.
     */
    void RemoveState();

    /**
     * @brief Adds/Removes states from stack. Runs at the beginning
     * of the game loop.
     */
    void ProcessStateChanges();

    /**
     * @brief Returns active game state.
     * @return Returns reference to the Active game state (state at the
     * top of the stack).
     */
    StatePtr& GetActiveGameState();

   private:
    // stack data container to store game states
    std::stack<StatePtr> states_;
    // member which tracks a new game state to be added to the stack
    StatePtr new_state_;
    // members to track whether a game state is to be added, replaced, or removed
    bool adding_;
    bool removing_;
    bool replacing_;
};
}  // namespace GameEngine

#endif
