#encoding=utf-8

import sys
import pygame
import traceback
from massa import *

tamanhoTela = (640,480)

def lerArquivoAnimacao(nomeArquivo):
	try:
		arquivo = open(nomeArquivo)
		passo = float(arquivo.readline())
		
		linhasArquivo = arquivo.readlines()
		animacao = []
		
		for linha in linhasArquivo:
			[y0,y1] = map(float,linha.split(','))
			animacao.append(((0.0,y0),(0.0,y1)))

		animacao = map(list,zip(*animacao))
		return passo, animacao

	except Exception, e:
		raise e

def criarLinhas(caixa1, caixa2,tela):
	pygame.draw.line(tela,(0,0,0),(tamanhoTela[0]/2,0),(caixa1.retangulo.centerx,caixa1.retangulo.top))
	pygame.draw.line(tela,(0,0,0),(caixa1.retangulo.centerx,caixa1.retangulo.bottom),(caixa2.retangulo.centerx,caixa2.retangulo.top))
	#pygame.draw.line(tela,(0,0,0),(x1,y1
	#pygame.draw.line(tela,(0,0,0),(caixa1.animacao),(caixa2.centex,caixa2.top))


def renderizar(passo, animacao):

	cores = {"VERMELHO": (255,0,0), "AZUL": (0,0,255), "VERDE": (0,255,0), "PRETO": (0,0,0), "BRANCO": (255,255,255)}
	#tamanhoTela = (640,480)
	
	pygame.init()

	tela = pygame.display.set_mode(tamanhoTela)
	pygame.display.set_caption("Visualização de Resolução de EDO")

	passoAtual = 0

	caixa1 = Massa(20, 10, cores["VERDE"], animacao[0], tela)
	caixa2 = Massa(20, 10, cores["AZUL"], animacao[1], tela)
		
	
	print passo*10
	aberto = True
	relogio = pygame.time.Clock()
	while aberto:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				aberto = False
				break

		tela.fill(cores["BRANCO"])
		criarLinhas(caixa1,caixa2,tela)
		caixa1.desenharProxPosicao()
		caixa2.desenharProxPosicao()

		pygame.display.flip()
		relogio.tick((1+(20/passo))/5)

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
