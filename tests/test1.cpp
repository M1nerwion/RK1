#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Robot.h"

TEST(Wake_test, test_WakeWordReceived) {
	Robot surena;
	SpeechRecognitionState* p_test = surena._speechRecognitionState;
	surena.WakeWordReceived();

	EXPECT_TRUE(surena.currentState == p_test);
}

TEST(Speech_test, test_SpeechDataReceived) {
	Robot surena;
	ObjectDetectionState* p_test = surena._objectDetectionState;
	surena.WakeWordReceived();
	surena.SpeechReceived("watch your front!");
	
	EXPECT_TRUE(surena.currentState == p_test);
}

TEST(Object_test, test_ObjectDetected) {
	Robot surena;
	surena.WakeWordReceived();
	surena.SpeechReceived("watch your front!");
	surena.NewObjectDetected({ "person" });
	FaceRecogntionState* p_test = surena._faceRecognitionState;

	EXPECT_TRUE(surena.currentState == p_test);
}

TEST(Face_test, test_face) {
	Robot surena;
	surena.WakeWordReceived();
	surena.SpeechReceived("watch your front!");
	surena.NewObjectDetected({ "person" });
	surena.NewObjectDetected({ "person" });
	WakeWordState* p_test = surena._wakeWordState;

	EXPECT_TRUE(surena.currentState == p_test);
}

TEST(Robot_test, test_robot) {
	Robot surena;
	ObjectDetectionState* p_test = surena._objectDetectionState;
	surena.SetState(surena._objectDetectionState);
	EXPECT_TRUE(surena.currentState == p_test);
}

int main(int argc, char** argv) {
	::testing::FLAGS_gmock_verbose = "error";
	::testing::InitGoogleTest(&argc, argv);
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}