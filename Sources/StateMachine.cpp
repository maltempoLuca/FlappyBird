//
// Created by Luca Maltempo on 20/11/21.
//

#include "../Headers/StateMachine.h"
namespace Maltempo {

    StateMachine::StateMachine() {

    }

    StateMachine::~StateMachine() {

    }

    void StateMachine::addState(Maltempo::StateRef newState, bool isReplacing) {
        this->adding = true;
        this->replacing = isReplacing;

        this->newState = std::move(newState);
    }

    void StateMachine::removeState() {
        this->removing = true;
    }

    void StateMachine::processStateChanges() {
        if (this->removing && !this->states.empty()) {
            this->states.pop();

            if (!this->states.empty()) {
                this->states.top()->resume();
            }
            this->removing = false;
        }

        if (this->adding) {
            if (!this->states.empty()) {
                if (this->replacing) {
                    this->states.pop();
                } else {
                    this->states.top()->pause();
                }
            }
            this->states.push(std::move(newState));
            this->states.top()->init();
            this->adding = false;

        }
    }

    StateRef & StateMachine::getActiveState() {
        return this->states.top();
    }


}