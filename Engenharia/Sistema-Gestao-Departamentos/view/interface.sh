#!/bin/bash


create_input(){
	rofi -dmenu -p "$1" -config view/style/input.rasi
}

create_message(){
	rofi -e "$1" -config view/style/message.rasi
}

create_options(){
	echo "$1" | rofi -sep '|' -dmenu -config view/style/dialog.rasi
}

create_dialog(){
	echo "$1" | rofi -sep '|' -mesg "$2" -dmenu -config view/style/dialog.rasi
}

if [[ $1 == "--show" ]]; then
	create_message "$2"
	#rofi -e "$2" -config view/style/message.rasi
	exit
fi

escolha=$(create_options "Cadastrar documento|Ver documento|Sair")

if [[ $escolha = "Cadastrar documento" ]]; then
	nome=$(create_input "Nome do documento: ")
	caminho=$(create_input "Caminho do documento: ")
	tipo=$(create_input "Tipo do documento: ")
	data=$(create_input "Data(DD/MM/YYYY): ")
	echo "CADASTRO#$nome#$caminho#$tipo#$data"
elif [[ $escolha = "Ver documento" ]]; then
	escolha=$(create_dialog "Nome|Caminho|Tipo|Data" "Buscar por qual informação?")
	busca=$(create_input "$escolha: ")
	echo "BUSCA#$escolha#$busca"
else
	echo "Sair"
fi
