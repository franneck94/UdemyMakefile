# Addtional Topics

## All Target

- Making multiple targets and you want all of them with the all target

## Terminal Commands in Targets

- Add an @ before a command to stop it from being printed
- Each command is run in an own shell

## Variables

- ?= only sets variables if they have not yet been set

## Conditions

- Check if a variable is empty
  - ifeq ($(strip $(VAR)),)
- Check if a variable is defined
  - ifdef VAR
