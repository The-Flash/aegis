
# Aegis Student Workbook

## Build a Linux Process Supervisor in Modern C++

**Duration:** 2 Weeks
**Difficulty:** Intermediate to Advanced
**Project Type:** Systems Programming
**Primary Goal:** Build a lightweight process supervisor similar to systemd, Supervisor, or PM2.

---

# Table of Contents

1. Introduction
2. Project Overview
3. Learning Outcomes
4. Architecture Overview
5. Week-by-Week Roadmap
6. Ticket 1 – Project Initialization
7. Ticket 2 – Dependency Management
8. Ticket 3 – Logging Infrastructure
9. Ticket 4 – Configuration Loader
10. Ticket 5 – Process Launching
11. Ticket 6 – Process Tracking
12. Ticket 7 – Graceful Shutdown
13. Ticket 8 – Supervisor Core
14. Ticket 9 – Monitoring Thread
15. Ticket 10 – Restart Policies
16. Ticket 11 – HTTP API
17. Ticket 12 – Process Log Capture
18. Ticket 13 – Automated Testing
19. Ticket 14 – Packaging
20. Ticket 15 – Final Polish
21. Final Architecture Review
22. Stretch Goals
23. Final Submission Checklist

---

# 1. Introduction

Welcome to Aegis.

Aegis is a lightweight process supervisor designed to teach practical systems programming in C++. By the end of this project you will have built a tool capable of:

* Launching processes
* Monitoring processes
* Restarting failed processes
* Exposing process status through HTTP
* Managing logs
* Reading configuration files
* Gracefully shutting down services

This project intentionally combines multiple engineering disciplines into a single cohesive application.

---

# 2. Project Overview

## Problem Statement

Modern applications often consist of multiple background services.

Examples:

* API servers
* Background workers
* Scheduled jobs
* Message queue consumers

These services need:

* Startup automation
* Monitoring
* Logging
* Restart policies

Your task is to build a simplified process supervisor that solves these problems.

---

# 3. Learning Outcomes

Upon completion, you should understand:

## Modern C++

* RAII
* Smart pointers
* STL containers
* Error handling
* Move semantics

## Build Systems

* CMake targets
* Dependency management
* Build configurations

## Linux Systems Programming

* Processes
* Signals
* Pipes
* Process monitoring

## Concurrency

* Threads
* Synchronization
* Race conditions

## Networking

* HTTP servers
* REST APIs

## Software Engineering

* Modular architecture
* Testing
* Packaging
* Documentation

---

# 4. Architecture Overview

## Core Components

### Configuration Loader

Reads YAML configuration files.

### Process Manager

Responsible for:

* Starting processes
* Stopping processes
* Tracking process metadata

### Supervisor

Coordinates all managed processes.

### Monitoring Service

Continuously checks process health.

### HTTP API

Provides operational visibility.

### Logging Layer

Records application events.

---

# 5. Week-by-Week Roadmap

## Week 1

Focus on foundations.

### Days 1–2

* Ticket 1
* Ticket 2

### Days 3–4

* Ticket 3
* Ticket 4

### Day 5

* Ticket 5

### Day 6

* Ticket 6

### Day 7

* Ticket 7

---

## Week 2

### Days 8–9

* Ticket 8

### Day 10

* Ticket 9

### Day 11

* Ticket 10

### Day 12

* Ticket 11

### Day 13

* Ticket 12

### Day 14

* Ticket 13–15

---

# 6. Ticket 1 – Project Initialization

## Objective

Create the project skeleton.

## Deliverables

* Git repository
* Folder structure
* Initial CMake configuration

## Research Topics

* CMake targets
* Out-of-source builds
* Repository organization

## Acceptance Criteria

* Project builds successfully
* Repository structure is documented

## Common Pitfalls

* Mixing source and build files
* Hardcoding paths

## Definition of Done

A clean checkout builds successfully.

---

# 7. Ticket 2 – Dependency Management

## Objective

Add external libraries.

## Dependencies

### yaml-cpp

Configuration parsing.

### spdlog

Logging.

### cpp-httplib

HTTP API.

### Catch2

Testing.

## Research Topics

* FetchContent
* Static vs shared libraries

## Acceptance Criteria

All dependencies build automatically.

## Common Pitfalls

* Global include directories
* Version pinning issues

---

# 8. Ticket 3 – Logging Infrastructure

## Objective

Create a centralized logging system.

## Features

* Console logging
* File logging
* Log levels

## Research Topics

* Structured logging
* Log rotation

## Acceptance Criteria

Application events are recorded consistently.

## Reflection

How would debugging change without logs?

---

# 9. Ticket 4 – Configuration Loader

## Objective

Load YAML process definitions.

## Requirements

Configuration should define:

* Process name
* Executable
* Arguments
* Restart policy

## Research Topics

* Configuration validation
* Schema design

## Acceptance Criteria

Invalid configurations are rejected gracefully.

---

# 10. Ticket 5 – Process Launching

## Objective

Launch external programs.

## Concepts

* Parent processes
* Child processes
* Process execution

## Research Topics

* Process creation
* Process replacement
* Process identifiers

## Acceptance Criteria

Managed processes start successfully.

## Reflection

What metadata should be stored for every process?

---

# 11. Ticket 6 – Process Tracking

## Objective

Track process state.

## Suggested States

* Starting
* Running
* Stopped
* Crashed

## Research Topics

* Finite state machines
* Process lifecycle management

## Acceptance Criteria

Current process state can be queried.

---

# 12. Ticket 7 – Graceful Shutdown

## Objective

Handle termination signals.

## Requirements

* Stop child processes
* Flush logs
* Exit cleanly

## Research Topics

* Signal handling
* Shutdown coordination

## Acceptance Criteria

No orphan processes remain.

## Reflection

Why is graceful shutdown important in production systems?

---

# 13. Ticket 8 – Supervisor Core

## Objective

Build the central orchestration engine.

## Responsibilities

* Start processes
* Stop processes
* Track status
* Coordinate monitoring

## Research Topics

* Single responsibility principle
* Service orchestration

## Acceptance Criteria

Supervisor manages all configured processes.

---

# 14. Ticket 9 – Monitoring Thread

## Objective

Monitor running processes.

## Requirements

* Background thread
* Health checks
* Process state updates

## Research Topics

* Thread lifecycle
* Synchronization primitives

## Acceptance Criteria

Supervisor detects process exits.

## Common Pitfalls

* Race conditions
* Deadlocks

---

# 15. Ticket 10 – Restart Policies

## Objective

Implement restart strategies.

## Policies

### Always

Always restart.

### Never

Never restart.

### On Failure

Restart only after unexpected termination.

## Research Topics

* Strategy pattern
* Backoff algorithms

## Acceptance Criteria

Policies behave as configured.

## Reflection

How would you prevent restart storms?

---

# 16. Ticket 11 – HTTP API

## Objective

Expose supervisor status.

## Endpoints

### Health

Returns service health.

### Processes

Returns process information.

## Research Topics

* REST principles
* JSON serialization

## Acceptance Criteria

Operational status is accessible remotely.

---

# 17. Ticket 12 – Process Log Capture

## Objective

Capture stdout and stderr.

## Requirements

* Per-process logs
* Log persistence

## Research Topics

* Pipes
* File descriptors

## Acceptance Criteria

Each process has independent logs.

---

# 18. Ticket 13 – Automated Testing

## Objective

Build a test suite.

## Test Areas

### Configuration

Valid and invalid configurations.

### State Machine

State transitions.

### Restart Logic

Policy behavior.

## Research Topics

* Unit testing
* Test isolation

## Acceptance Criteria

Critical business logic is tested.

---

# 19. Ticket 14 – Packaging

## Objective

Prepare the application for distribution.

## Deliverables

* Installation target
* Release package

## Research Topics

* CMake install rules
* Release engineering

## Acceptance Criteria

Application installs correctly on a clean system.

---

# 20. Ticket 15 – Final Polish

## Objective

Improve maintainability.

## Tasks

* Documentation
* Architecture diagrams
* Operational guide
* User guide

## Acceptance Criteria

Another engineer can use the project without assistance.

---

# 21. Final Architecture Review

Before submission, verify:

## Separation of Concerns

Each component has a clear responsibility.

## Error Handling

Failures are handled gracefully.

## Logging

Important events are recorded.

## Testability

Business logic can be tested independently.

## Maintainability

Code is understandable and documented.

---

# 22. Stretch Goals

Complete these only if time remains.

## Resource Monitoring

Track:

* CPU usage
* Memory usage

## Dashboard

Create a web UI.

## Hot Reloading

Reload configuration automatically.

## Plugin System

Allow external extensions.

## Metrics

Export metrics for monitoring systems.

---

# 23. Final Submission Checklist

## Build

* [ ] Clean build succeeds
* [ ] Dependencies install automatically

## Functionality

* [ ] Processes launch
* [ ] Processes stop
* [ ] Restart policies work
* [ ] Monitoring works

## API

* [ ] Health endpoint works
* [ ] Process endpoint works

## Logging

* [ ] Application logs work
* [ ] Process logs work

## Testing

* [ ] Tests pass
* [ ] Critical logic covered

## Documentation

* [ ] README complete
* [ ] Architecture diagram included
* [ ] Setup instructions included

## Packaging

* [ ] Install target works
* [ ] Release package generated

## Final Demonstration

You should be able to demonstrate:

1. Starting the supervisor
2. Launching managed processes
3. Viewing process status
4. Killing a process
5. Automatic restart
6. Viewing logs
7. Graceful shutdown

If you can successfully demonstrate all seven items, Aegis can be considered complete.
