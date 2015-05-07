#encoding=utf-8

import pygame
from massa import *

def lerArquivoAnimacao(nomeArquivo):
	arquivo = open(nomeArquivo)
	passo = linhasArquivo[0]
	linhasArquivo = arquivo.readlines()

def main():

	cores = {"VERMELHO": (255,0,0), "AZUL": (0,0,255), "VERDE": (0,255,0), "PRETO": (255,255,255), "BRANCO": (0,0,0)}
	tamanhoTela = (640,480)

	pygame.init()

	tela = pygame.display.set_mode(tamanhoTela)
	pygame.display.set_caption("Visualização de Resolução de EDO")

	passosAnimacao = [[0,10],[0,15],[0,20],[0,25],[0,30],[0,35],[0,40]]
	passoAtual = 0

	caixa1 = Massa(20,10,cores["VERDE"],passosAnimacao,tela)

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
			relogio.tick(len(passosAnimacao))


if __name__ == '__main__':	
	main()