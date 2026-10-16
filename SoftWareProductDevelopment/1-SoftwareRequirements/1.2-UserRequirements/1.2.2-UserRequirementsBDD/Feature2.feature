# language: en
Feature: Exercise Prescription by Therapist
  As a physical therapist
  I want to assign a customized rehabilitation program to a patient
  So that the patient follows appropriate walking exercises tailored to their recovery stage

  Scenario: Assigning a new exercise plan
    Given the therapist is logged into the system and selects a patient profile
    When the therapist configures exercise parameters (duration, step frequency, symmetry goals)
    Then the system should save the personalized plan
    And make it available in the patient's mobile or web interface
