

## Repo Organization

**Source files**
- The string and list implementations we are focused on in this lab are in `list.{c|h}` and `ustr.{c|h}`.
- The `pset1.{c|h}` files have implementations drawn from problem set 1.
- The `test_XXX.c` files have specific code to test out different functions. For
example `test_len.c` calls `len` on user input in a loop and prints the result

**Building**
- Run `make XXX.test` where XXX is one of the names in `test_XXX.c` to get a
binary for that test. For example, `make len.test` will build `test_len.c`
- Object files are stored in a generated `obj` directory that is ignored by git
(feel free to look in there and at the Makefile to see the setup)



