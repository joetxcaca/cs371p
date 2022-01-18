.DEFAULT_GOAL := all

all:

clean:
	cd cpp; make --no-print-directory clean

config:
	git config -l

init:
	git init
	git remote add origin git@gitlab.com:gpdowning/cs371p.git
	git add README.md
	git commit -m 'first commit'
	git push -u origin master

pull:
	make --no-print-directory clean
	@echo
	git pull
	git status

push:
	make --no-print-directory clean
	@echo
	git add .gitignore
	git add .gitlab-ci.yml
	git add cpp
	git add Makefile
	git add notes
	git add README.md
	git add uml
	git commit -m "another commit"
	git push
	git status

status:
	make --no-print-directory clean
	@echo
	git branch
	git remote -v
	git status

sync:
	cd cpp; make --no-print-directory sync
	@echo
	cd uml; make --no-print-directory sync

versions:
	cd cpp; make --no-print-directory versions
