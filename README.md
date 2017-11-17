# CNO
A low-level framework for ANSI C intended to be small, simple, and easily embeddable.
## Status

| Branches | Version | Commit | Test | Last Commit |
| --- | --- | --- | --- | --- |
| master | 0.3.3 | 

## Details
Designed as a "thin-layer" abstraction over the C standard Library and a few select (mostly internal) dependencies, CNO aims to abstract away the many quirks and catch'ems of different C implementations and environments while also reducing the boilerplate and tedium involved in writing a modern, platform-agnostic C application.
### Features
- Friendly. CNO, and all of its code, is MIT License; users are more than welcome to use its source and header files with or without modication and attribution.
- Simple. CNO, in opposition to other C framework, requires no system installs, complex linking instructions, or presumptive EULAs.
- Correct. CNO adheres strictly to the ANSI C standard (C90), has a clean namespace, and keeps global state completely optional.
- Minimal. CNO abstracts away a small set of features considered to be essential to modern media application and nothing else.
- Documented.
