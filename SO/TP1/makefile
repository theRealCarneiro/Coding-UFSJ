CC = cc
CCFLAGS = 
SRC_PATH = src/

TARGET_COMMANDER = process_commander
FILES_COMMANDER = process_commander.c 
SRC_COMMANDER = ${FILES_COMMANDER:%.c=$(SRC_PATH)%.c} 
OBJ_COMMANDER = ${FILES_COMMANDER:.c=.o}

TARGET_MANAGER = process_manager
FILES_MANAGER = process_manager.c
SRC_MANAGER = ${FILES_MANAGER:%.c=$(SRC_PATH)%.c}
OBJ_MANAGER = ${FILES_MANAGER:.c=.o}

.o:
	${CC} -c ${SRC_COMMANDER}
	${CC} -c ${SRC_MANAGER}

commander:	.o	${OBJ_COMMANDER}	${OBJ_MANAGER}
	${CC} ${OBJ_COMMANDER} -o ${TARGET_COMMANDER} ${CCFLAGS}
	${CC} ${OBJ_MANAGER} -o ${TARGET_MANAGER} ${CCFLAGS}

${OBJ_COMMANDER}: 

${OBJ_MANAGER}: headers/process_manager.h

clean:
	rm -rf *.o ${TARGET_MANAGER} ${TARGET_COMMANDER}

.PHONY: clean 
