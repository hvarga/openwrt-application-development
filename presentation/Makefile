.PHONY: all pdf clean

all: clean pdf

pdf:
	git log -1 --format=\\newcommand{\\commitid}{%H} > current_commit.tex
	git log -1 --date=iso --format=\\newcommand{\\commitdate}{%ad} >> current_commit.tex

	latexmk -pdf -silent -time -pdflatex="pdflatex -interaction=nonstopmode -synctex=1" -use-make -aux-directory=build --output-directory=build main.tex
	cp build/main.pdf build/openwrt-application-development.pdf
clean:
	rm -rf build
	rm -f current_commit.tex
