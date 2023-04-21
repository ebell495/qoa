qoa-fuzz: qoa-fuzz.c
	clang -g -fsanitize=fuzzer,memory,undefined,nullability -fno-sanitize-recover=undefined -o qoa-fuzz qoa-fuzz.c