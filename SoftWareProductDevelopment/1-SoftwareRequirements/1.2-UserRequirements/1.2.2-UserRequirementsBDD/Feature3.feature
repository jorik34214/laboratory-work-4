# language: en
Feature: Progress Tracking and Statistics
  As a patient
  I want to view my rehabilitation progress and session history
  So that I can evaluate my improvement over time

  Scenario: Viewing detailed session statistics
    Given the patient has completed multiple walking exercise sessions
    When the patient opens the progress dashboard
    Then the system should display graphs of step symmetry, posture accuracy, and session duration
    And show a summary of achievements for the current week
