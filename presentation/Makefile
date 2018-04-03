.PHONY: all pdf clean

all: clean pdf

pdf:
	git log -1 --format=\\newcommand{\\commitid}{%H} > current_commit.tex
	git log -1 --date=iso --format=\\newcommand{\\commitdate}{%ad} >> current_commit.tex

	latexmk -pdf -silent -time -pdflatex="pdflatex -interaction=nonstopmode -synctex=1" -use-make -aux-directory=build --output-directory=build main.beamer.tex
	cp build/main.beamer.pdf build/openwrt-application-development-beamer.pdf

	latexmk -pdf -silent -time -pdflatex="pdflatex -interaction=nonstopmode -synctex=1" -use-make -aux-directory=build --output-directory=build main.handout.tex
	cp build/main.handout.pdf build/openwrt-application-development-handout.pdf
clean:
	rm -rf build
	rm -f current_commit.tex
