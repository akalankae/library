# Makefile to generate my personal library utility functions
# Library name: libpersonal.a
CC := gcc

target := libpersonal.a
src_dir := src
src_files := $(wildcard $(src_dir)/*.c)
build_dir := build
obj_files := $(patsubst $(src_dir)/%.c,$(build_dir)/%.o,$(src_files))
include_dir := include
header_files := $(wildcard $(include_dir)/*.h)

.PHONY: print clean

$(target): $(obj_files)
	$(AR) rcs $@ $?

$(obj_files): $(build_dir)/%.o: $(src_dir)/%.c $(include_dir)/%.h
	mkdir -p $(build_dir)
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@  $<

clean:
	$(RM) --recursive --verbose $(build_dir)

uninstall: clean
	$(RM) $(target)
