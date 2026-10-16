# language: en
Feature: Execution of Gait Rehabilitation Exercises
  As a patient
  I want to perform walking exercises with real-time camera tracking
  So that I can restore my gait correctly and safely at home

  Scenario: Successful real-time monitoring during a walking exercise
    Given the patient has selected the "Gait Restoration" exercise
    And the device camera is properly positioned and active
    When the patient starts the exercise session
    Then the system should track body posture, steps, and symmetry using the camera
    And provide real-time feedback if a deviation occurs
