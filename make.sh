#!/usr/bin/env bash
######################################################################################
###                       automação de copilador em shellscript                    ###
###                    based in https://github.com/DIEGOHORVATTI/run               ###
######################################################################################

# info versão
function fVersao(){
	echo -e "\n"
	echo -e "┌───────────────────────────────────────┐"
	echo -e "│                                       │"
	echo -e "│    Run v0.0.1 | by Diego Horvatti     │"
	echo -e "│   https://github.com/DIEGOHORVATTI    │"
	echo -e "│                                       │"
	echo -e "└───────────────────────────────────────┘"
	echo -e "\n"
}

# Help do programa
function fHelp(){
	echo -e "\n"
	echo -e "┌───────────────────────────────────────┐"
	echo -e "│                                       │"
	echo -e "│ [ info ]                              │"
	echo -e "│ -v, --version.: versão do softwere    │"
	echo -e "│ -h, --help....: informações das flags │"
	echo -e "│                                       │"
	echo -e "│ [ dev ]                               │"
	echo -e "│ --create-file.: criar arquivo.c       │"
	echo -e "│ --gitignore...: criar .gitgnore       │"
	echo -e "│ --git.........: commit & push         │"
	echo -e "│ --build.......: verificação de bugs   │"
	echo -e "│                                       │"
	echo -e "│ [ user ]                              │"
	echo -e "│ --start.......: iniciar compilação    │"
	echo -e "│ --config......: arquivo configuração  │"
	echo -e "│                                       │"
	echo -e "│ [ dependencies ]                      │"
	echo -e "│ obrigratório: 'gcc or g++'            │"
	echo -e "│ optativa: 'cppcheck', 'wget', 'git'   │"
	echo -e "│                                       │"
	echo -e "│                                       │"
	echo -e "│ used: make --start                    │"
	echo -e "│                                       │"
	echo -e "└───────────────────────────────────────┘"
	echo -e "\n"
}

# Adicionar arquivo .gitgnore
function fGitgnore(){
	wget https://gist.githubusercontent.com/DIEGOHORVATTI/30462a7868ae1df718a6c32c505a9ea3/raw/77d407af7e041727e6025f30531683aaab893a7d/.gitignore
	clear
	echo -e "\n"
	echo -e "┌───────────────────────────────────────┐"
	echo -e "│                                       │"
	echo -e "│        Create file:  .gitgnore       │"
	echo -e "│                                       │"
	echo -e "└───────────────────────────────────────┘"
	echo -e "\n"
}

# Criar arquivo C com a estrutura base para testes
function creat_file_f(){
	read -p ' New file: ' nome
	echo -e "\n"
	wget https://gist.githubusercontent.com/DIEGOHORVATTI/f1272263f3db0118f2d5d5bb3df0de8d/raw/ad09444126da9bb50bdd98b62cf5957f5feb895d/min.c -O $nome
	code $nome
	clear
}

# Atualizar repositória a cada minuto setado por usuário com a data do sistema
function fGitAll(){
	read -p ' Time: ' time_
	while :; do
		git branch -M main && 
		git add . && 
		git commit -m "$(date +'[%d/%m/%Y] [%H:%M] -- {%j, %A}')" && 
		git push -u origin main &&
		clear &&
		for ((i=$time_; i >= 0; i--)); do       
			echo -e "\n\033[0;34m🕗 $(($i))m\033 \033[1;32m $(date +'[%d/%m/%Y] [%H:%M] { %A }')\033[0m"
			sleep 1m 
		done
	done
}

# Atualizar repositória da branch "main" com um commit setado do teclado 
function f_GitRead(){
	read -p ' New commit: ' git
	git branch -M main && 
	git add . && 
	git commit -m "$git" && 
	git push -u origin main &&
	clear &&
	echo -e "\n\033[0;34m ✓✓:\033[0m $git \n"
}

# Iniciar compilação
function fStart(){
	clear && 
	#cppcheck ./$i && 
	echo -e "\n───────────────────────────────────────\n" && 
	gcc ./build/main.c -o ./bin/run.bin && ./bin/run.bin && 
	echo -e "\n\n───────────────────────────────────────\n"
}

# Iniciar compilação
function fDebug(){
	clear && 
	cppcheck ./build/main.c && 
	echo -e "\n───────────────────────────────────────\n" && 
	gcc ./build/main.c -o ./bin/run.bin && ./bin/run.bin && 
	echo -e "\n\n───────────────────────────────────────\n"
}

# Swith case de opções de flags
for i in "$@"; do
	case $i in
		-v | --version) 
			fVersao
		;;
		-h | --help) 
			fHelp
		;;
		--create-file)
			creat_file_f
		;;
		--gitignore)
			fGitgnore
		;;
		--git)
			f_GitRead
		;;
		--git-date)
			fGitAll
		;;
		--config)
			nano ./config.ini
			clear
		;;
		--debug)
			fDebug
			echo -e " Nova deburação [ \033[0;34m"Y"\033[0m / \033[0;31m"N"\033[0m ]"
			read -p " >> " teclado
			case $teclado in
				y | Y)
					./make.sh --debug
				;;
				n | N)
					exit
				;;
				git)
					f_GitRead
					./make.sh --start
				;;
				*)
					exit
				;;
			esac
		;;
		--start)
			fStart
			echo -e " Nova verificação [ \033[0;34m"Y"\033[0m / \033[0;31m"N"\033[0m ]"
			read -p " >> " teclado
			case $teclado in
				y | Y)
					./make.sh --start
				;;
				n | N)
					exit
				;;
				git)
					f_GitRead
					./make.sh --start
				;;
				*)
					exit
				;;
			esac
	esac
done