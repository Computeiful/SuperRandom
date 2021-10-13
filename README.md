# SuperRandom

This is an [LCG](https://en.wikipedia.org/wiki/Linear_congruential_generator) based PRNG in C. It was made as a safer version of [this PRNG](https://github.com/Computeiful/QuickRandom), though it is not quite as fast.

This PRNG is **NOT** zero sensitive, has a very long period and tries to mitigate the known issue of LCGs having bad quality lower bits.

See `Main.c` for usage examples.

---

I've found speeds of ~3 GB/s can be achieved on modern hardware, though YMMV.