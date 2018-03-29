# OpenWrt - Application Development

The goal of this project is to write a presentation which will help you to learn the basic knowledge about the OpenWrt and its ecosystem so that you can create your own custom application which will run on OpenWrt.

Presentation itself is written using LaTeX.

## How to Generate a PDF

To be able to generate a PDF yourself you have to have quite a large collection of tools. It is highly recommended to use prepared Docker Image. This Docker Image contains everything you need to start working on the presentation. Alternative is to manually install the LaTeX system like TeX Live yourself which is out of scope of this documentation. Follow the sections below to configure your environment using prepared Docker Image.

### Docker Image

There is a Docker Image already prepared for you. You need to have a Docker installed before using prepared Docker Image.

After the Docker is installed, execute following command to get the prepared Docker Image:

```plain
docker pull hvarga/latex-docker
```

And that's it. You can proceed to chapter [Download the Source Materials](#download-the-source-materials).

For more information about the prepared Docker Image, read the https://github.com/hvarga/latex-docker.

### Download the Source Materials

Second step is to download the source materials for the presentation. This can be accomplished using the Git to clone the repository. You need to have Git installed on your system. So, one more tool to install.

Use your system package manager to install Git or go to http://git-scm.com/downloads and choose your operating system and follow directions.

Now that you installed the Git, it is time to clone the repository.

Open up your terminal and enter the following:

```plain
git clone git@github.com:hvarga/openwrt-application-development.git
```

Git will do its magic and you will have the source materials.

### Generate PDF

Position yourself in the root folder of cloned repository and execute following command:

```plain
docker run --rm -v ${PWD}:/home/latex/work -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --entrypoint make hvarga/latex-docker
```

You don't have Docker or this Docker Image? Follow [Docker Image](#docker-image) chapter.

Above command will start the Docker Container out of the Docker Image that you pulled earlier in [Docker Image](#docker-image) chapter. Docker Container will execute `make` and `make` will call `latexmk` which will take care of generating the PDF document. PDF will be stored in the `build/openwrt-application-development.pdf`. Enjoy reading!

## How to Contribute to the Presentation

Since this presentation is under the Creative Commons license, everyone is free to share and adapt it.

So, if you are willing to contribute by correcting grammar mistakes, making structural changes, alter the visual appearance for better readability, supplement some sections or chapters with additional information's that can help out a reader or even writing a new sections or chapters than by any means - contribute.

### Learn LaTeX

This presentation is written using the [LaTeX](http://latex-project.org/). So, if you want to contribute to the presentation than, obviously, you need to know LaTeX. Its homepage has a lot of good information's for reading. But if I have to single out just one good book to read, than I would recommend ["The (Not So) Short Introduction to LaTeX2e"](http://ctan.tug.org/tex-archive/info/lshort/english/lshort.pdf). If you don't have the time to invest in learning another technology or you are just too lazy than, please, at least read this recommended book.

### Configure Environment

Now to the fun part - in order to contribute, first, follow the [How to Generate a PDF](#generate-pdf) section of this document. Note that if you want to contribute to the presentation than you need to have the Git. Without it, you cannot send me your changes that you made to the presentation.

Contributions to this presentation will be handled by the Git and the GitHub. So, [create an account](https://github.com/join) on the GitHub if you don't have one already. You will use Git to make versions of your changes and the GitHub [pull requests](https://help.github.com/articles/using-pull-requests) to send me your changes.

Please, read a bit about the [Git](http://git-scm.com/doc) and the [GitHub](https://help.github.com/) itself before you start with your contributions.

### Use LaTeX and Vector Drawing Editor

Docker Image that you pulled earlier in [Docker Image](#docker-image) chapter, besides generating PDF, also comes with a LaTeX editor called [TeXstudio](https://www.texstudio.org/) and vector drawing editor called [Ipe](http://ipe.otfried.org/).

#### TeXstudio

To run TeXstudio, execute following command in the root folder of cloned repository:

```plain
docker run --rm -v ${PWD}:/home/latex/work -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix hvarga/latex-docker --ini-file /home/latex/profile.txsprofile
```

If you are experiencing problems with running above command, please read the https://github.com/hvarga/latex-docker.

After TeXstudio loads, you need to open the `main.tex` file. Presentation root is located in `/home/latex/work` and the `main.tex` is available at `/home/latex/work/presentation/main.tex`.

`main.tex` is the root document of the project since it contains `\begin{document}` statement.

#### Ipe

To run Ipe, execute following command in the root folder of cloned repository:

```plain
docker run --rm -v ${PWD}:/home/latex/work -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix --entrypoint ipe hvarga/latex-docker
```

Ipe saves drawings in PDF files which can then be directly included by LaTeX. Ipe also allows you to reopen your existing PDF made by Ipe. Besides this, it has a nice features like object snapping, grouping and aligning. Basic geometry primitives like lines, splines, polygons, circles etc.

Happy contributing!

## License

<a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/3.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/">Creative Commons Attribution-ShareAlike 3.0 Unported License</a>.
