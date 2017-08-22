#include <iostream>
#include <string.h>
#include "Leap.h"

using namespace Leap;


class SampleListener : public Listener {
    public:
    virtual void onConnect(const Controller&);
    virtual void onFrame(const Controller&);
};

void SampleListener::onConnect(const Controller& controller) {
    std::cout << "Connected" << std::endl;
}

void SampleListener::onFrame(const Controller& controller) {
	const Frame frame = controller.frame();
    /*std::cout << "Frame id: " << frame.id()
          << ", timestamp: " << frame.timestamp()
          << ", hands: " << frame.hands().count()
          << ", fingers: " << frame.fingers().count();*/

	Leap::HandList hands = frame.hands();
	
	for (int i = 0; i < hands.count(); i++){
		Leap::Hand hand = hands[i];
		std::cout << "id:" << hand.id() << "\n";
		std::cout << "\tfingers:" << hand.fingers().count() << "\n";
		std::cout << "\tstr:" << hand.grabStrength() << "\n";
		std::cout << "\tX:" << hand.palmPosition().x << "\n";
		std::cout << "\tY:" << hand.palmPosition().y << "\n";
		std::cout << "\tZ:" << hand.palmPosition().z << "\n";

	}
	
}


int main(int argc, char** argv) {

	SampleListener listener;
    Controller controller;

    controller.addListener(listener);

    // Keep this process running until Enter is pressed
    std::cout << "Press Enter to quit..." << std::endl;
    std::cin.get();

	// Remove the sample listener when done
    controller.removeListener(listener);

    return 0;
}