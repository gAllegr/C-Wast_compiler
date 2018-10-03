all: bison flex compile

# Produce Bison file .tab.c and header file .tab.h
# bison -d grammar.y
# --report=all produces detail on automaton
# --degub instrument the parser for tracing
# -v verbose mode (produces a .output file)
# --graph[=FILE] also output a graph of the automaton
bison:
	mkdir -p ./bin
	bison --report=all --debug -v --graph=grammar.dot -d ./src/grammar.y
	mv grammar.tab.* grammar.dot grammar.output ./bin/

# Produce Flex .yy.c
flex:
	flex ./src/lex.l
	mv lex.yy.c ./bin

# Generate compiler
compile: 
	gcc ./src/utils.c ./src/list.c ./src/ast.c ./src/symtab.c ./src/wat.c ./bin/grammar.tab.c ./bin/lex.yy.c -lfl -o ./bin/compiler.out

# Save compiler graph as a png image
image:
	@dot ./bin/grammar.dot -Tpng -o ./compiler.png

# Run compiler
run:
	@mkdir -p ./output_code; \
	echo "Enter C source code: "; \
	read SOURCE; \
	./bin/compiler.out $$SOURCE

# Remove everything from output_code folder
clean:
	@rm ./output_code/*

# load final code to server folder
load:
	@sudo cp ./output_code/* /var/www/html/