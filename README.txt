***********************************************************************************************
*                                      TESTE JUNIOR - MARS ROVERS                             *
***********************************************************************************************
* Informações Técnicas:									      *
*	->Linguagem de programação: C							      *
*	->IDE: CodeBlock (Pode ser baixado em http://www.codeblocks.org/downloads 	      *
*	->SO: Windows 10 Education							      *
*	->RAM: 4GB									      *
* 	->Para a compilação dos arquivos foi utilizado o GNU GCC			      *
* 											      *
* Intruções de Execução do Mar Rovers:   						      *
*	->Execução do programa:								      *
*		# Pode ser usado qualquer IDE que compile e execute a linguagem C (desde que  *
*		  que essa o SO tenha o GNU GCC instalado. Algumas IDES já instalam    	      *
*		  autimente o GCC, como por exemplo o DEV C++.				      *
*											      *
*		  Para isso, crie um novo projeto na IDE utilizada e importe o arquivo	      *
*		  "main.c" disponível no GitHub: 					      *
*		  Em seguinda compile e execute o arquivo "main.c			      *
* 											      *
*		# Outra forma para execução do programa é utilizar o arquivo "MARSROVERS.exe" *
*		  também disponível no GitHub indicado (desde que o GCC esteja inslado em     *
*		  em sua máquina). Baixe o arquivo, clique duas vezes e o programa será	      * 		
*		  executado. 								      *
*											      *
*		# Caso não queira utilizar nenumaIDE, o programa pode ser compilado e 	      *
*		  execuado direto no prompt de comando do Windows. Como o GCC já instalado    *
*		  no seu Sistema, baixe o arquivo "main.c" em sua máquina, abra o prompt de   *
*		  comando e vá até o local onde o arquivo está salvo.  			      *
*		  	Para compilar: gcc main.c -o MARSROVERS.exe 			      *
*			Para executar: MARSROVERS.exe   				      *
*   											      *
*		# A especificação do programa, juntamente com a entrada e saída do programa   *
*		  está disponibilizada no arquivo MarsRovers.doc no GitHub já indicado.	      *
*		  Basta digitar a entrada conforme especificado, e a saida será impressa na   *
*		  tela. 								      *
*											      *
*		# Uma ou mais entradas podem serem dadas ao programa sequentemente após a     *
*		  saída de cada entrada.	 					      *
* 											      *
*		# O programa considera apenas um Rover por saída. Portanto, caso a entrada    *
*		  tenha mais de um rover, esse(s) não serão considerados obstáculos para o    *
*		  movimento do Rover que está sendo executado no momento. Apenas as margens   *
*		  da grid que serão obstáculos. 					      *
* 											      *		
* Pastas no GitHub:									      *	
*	-> Existem duas pastas no GitHub acessado pelo link: 				      *
*		# CodigoFonte: Contém o arquivo 'main.c' com a implementação do programa.     *
*											      *
*		# TesteCodigoFonte: Contém o arquivo 'main.c' com a implementação do programa *
*	          com a diferença que a saída irá gerar uma matriz mostrando o caminho feito  *
*		  pelo Rover executado no momento. A matriz é composta por pontos '.' que     *
*		  representam os quadrantes que o Rover pode estar. A posição em que o Rover  *
*		  se encontra, é representada por 'S', 'W', 'E' ou 'N', que também representa *
*		  a sua orientação. Dessa forma é possível acompanhar o caminho feito pelo    *
*		  Rover, utilizando esse arquivo como um teste automatizado para conferir se  *
*		  se a saída está correta. 						      *
* 											      *
* 											      *
* Autor: Magjeander Oliveira Silva     							      *
* Email: magjeander@yahoo.com.br 							      *
***********************************************************************************************
