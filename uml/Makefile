.DEFAULT_GOAL := all

all:

sync:
	@echo ~/examples/uml/
	@rsync -p -r -t -u -v --delete         \
    --exclude "*"                          \
    ~/examples/uml/ .
