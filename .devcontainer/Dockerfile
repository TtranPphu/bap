FROM ubuntu:22.04

RUN apt update && apt upgrade -y
RUN apt install sudo zsh git vim zip -y
RUN apt install build-essential python3-pip wget -y
RUN apt install bpytop -y

RUN wget http://archive.ubuntu.com/ubuntu/pool/main/o/openssl/libssl1.1_1.1.0g-2ubuntu4_amd64.deb
RUN apt install ./libssl1.1_1.1.0g-2ubuntu4_amd64.deb -y
RUN rm libssl1.1_1.1.0g-2ubuntu4_amd64.deb

RUN wget https://github.com/eosio/eos/releases/download/v2.1.0/eosio_2.1.0-1-ubuntu-20.04_amd64.deb
RUN apt install ./eosio_2.1.0-1-ubuntu-20.04_amd64.deb -y
RUN rm eosio_2.1.0-1-ubuntu-20.04_amd64.deb

RUN wget https://github.com/EOSIO/eosio.cdt/releases/download/v1.8.1/eosio.cdt_1.8.1-1-ubuntu-20.04_amd64.deb
RUN apt install ./eosio.cdt_1.8.1-1-ubuntu-20.04_amd64.deb -y
RUN rm eosio.cdt_1.8.1-1-ubuntu-20.04_amd64.deb

RUN mkdir /usr/share/fonts/truetype/meslo
RUN wget https://github.com/romkatv/powerlevel10k-media/raw/master/MesloLGS%20NF%20Regular.ttf \
    -O /usr/share/fonts/truetype/meslo/MesloLGSNFRegular.ttf
RUN wget https://github.com/romkatv/powerlevel10k-media/raw/master/MesloLGS%20NF%20Bold.ttf \
    -O /usr/share/fonts/truetype/meslo/MesloLGSNF20Bold.ttf
RUN wget https://github.com/romkatv/powerlevel10k-media/raw/master/MesloLGS%20NF%20Italic.ttf \
    -O /usr/share/fonts/truetype/meslo/MesloLGSNFItalic.ttf
RUN wget https://github.com/romkatv/powerlevel10k-media/raw/master/MesloLGS%20NF%20Bold%20Italic.ttf \
    -O /usr/share/fonts/truetype/meslo/MesloLGSNFBoldItalic.ttf

COPY openssl.cnf /usr/lib/ssl/openssl.cnf

RUN adduser --shell /usr/bin/zsh --gecos '' --ingroup sudo --disabled-password wg
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
USER wg

RUN sh -c "$(wget https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"
RUN git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k

COPY .zshrc /home/wg
COPY .p10k.zsh /home/wg