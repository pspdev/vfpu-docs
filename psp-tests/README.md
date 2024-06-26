
Here are a bunch of independent (yet related) tests. Most are autogenerated
but some are manually crafted. The purpose of the tests is to cover all
assertions and specifications given by the documentation.

Here follows an index of said tests:

 - accuracy: Contains a small program that calculates the accuracy of some
   operations that have less precision than what an fp32 can hold. This data
   has been fed to the YAML instruction specification.

 - functional: Tests every VFPU instruction and validates its pseudo-code
   description present in `inst-vfpu-desc.yaml`. The pseudocode is compiled as
   C code and used to validate the results produced by the native instruction.
   It also emulates prefix behaviour and outputs a prefix compatibility matrix.
   These tests are autogenerated by `gen-tests.py`.

 - manual: This is a collection of tests that exercise some corner cases, bugs
   and other interesting conditions found in the VFPU. As the name indicates
   it is manually crafted to test instructions or conditions that are difficult
   to auto-generate (or just doesn't make sense).

 - performance: Tests every VFPU instruction and calculates its throughput and
   latency. This test is autogenerated by `gen-perf-tests.py`

 - regcompat: Tests register overlap compatibility for every VFPU instruction.
   This test is autogenerated by `gen-regtests.py`


