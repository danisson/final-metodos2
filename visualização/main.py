#encoding=utf-8

import sys
import pygame
import traceback
from massa import *

def lerArquivoAnimacao(nomeArquivo):
	try:
		arquivo = open(nomeArquivo)
		passo = float(arquivo.readline())
		
		linhasArquivo = arquivo.readlines()
		animacao = []
		
		for linha in linhasArquivo:
			y = float(linha)
			animacao.append([0,y])

		return passo, animacao

	except Exception, e:
		raise e

def renderizar(passo, animacao):

	cores = {"VERMELHO": (255,0,0), "AZUL": (0,0,255), "VERDE": (0,255,0), "PRETO": (0,0,0), "BRANCO": (255,255,255)}
	tamanhoTela = (640,480)

	pygame.init()

	tela = pygame.display.set_mode(tamanhoTela)
	pygame.display.set_caption("Visualização de Resolução de EDO")

	passoAtual = 0

	caixa1 = Massa(20, 10, cores["VERDE"], animacao, tela)

	aberto = True
	relogio = pygame.time.Clock()
	while aberto:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				aberto = False
				break

			tela.fill(cores["BRANCO"])
			caixa1.desenharProxPosicao()
			pygame.display.flip()
			relogio.tick(passo/10)

def main():
	nomeArquivo = sys.argv[1]
	print(nomeArquivo)
	try:
		passo, animacao = lerArquivoAnimacao(nomeArquivo)
	except Exception, e:
		traceback.print_exc()
		print "Informe um nome de arquivo válido."
		sys.exit(1)

	renderizar(passo, animacao)

if __name__ == '__main__':	
	main()