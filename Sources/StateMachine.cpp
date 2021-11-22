//
// Created by Luca Maltempo on 20/11/21.
//

#include "../Headers/StateMachine.h"
namespace Maltempo {

    void StateMachine::addState(StateRef newState, bool isReplacing) {
        this->isAdding = true;
        this->isReplacing = isReplacing;

        this->newState = std::move(newState);
    }

    void StateMachine::removeState() {
        this->isRemoving = true;
    }

    void StateMachine::processStateChanges() {
        if (this->isRemoving && !this->states.empty()) {
            this->states.pop();
            if (!this->states.empty()) {
                this->states.top()->resume();
            }
            this->isRemoving = false;
        }

        if (this->isAdding) {
            if (!this->states.empty()) {
                if (this->isReplacing) {
                    this->states.pop();
                } else {
                    this->states.top()->pause(); // perche non lo abbiamo rimosso, quindi lo stoppiamo.
                }
            }
            this->states.push(std::move(newState));
            this->states.top()->init();
            this->isAdding = false;
        }
    }

    StateRef & StateMachine::getActiveState() {
        return this->states.top();
    }


}