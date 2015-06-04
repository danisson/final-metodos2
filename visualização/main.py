#encoding=utf-8

import sys
import pygame
import os
import traceback
from caixa import *
from molavertical import *

tamanhoTela = (640,480)

_image_library = {}
def get_image(path):
        global _image_library
        image = _image_library.get(path)
        if image == None:
                canonicalized_path = path.replace('/', os.sep).replace('\\', os.sep)
                image = pygame.image.load(canonicalized_path)
                _image_library[path] = image
        return image

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

"""def criarLinhas(caixa1, caixa2,tela):
	pygame.draw.line(tela,(0,0,0),(tamanhoTela[0]/2,0),(caixa1.retangulo.centerx,caixa1.retangulo.top))
	pygame.draw.line(tela,(0,0,0),(caixa1.retangulo.centerx,caixa1.retangulo.bottom),(caixa2.retangulo.centerx,caixa2.retangulo.top))
"""

def renderizar(passo, animacao):

	cores = {"VERMELHO": (255,0,0), "AZUL": (0,0,255), "VERDE": (0,255,0), "PRETO": (0,0,0), "BRANCO": (255,255,255)}
	#tamanhoTela = (640,480)
	
	pygame.init()

	tela = pygame.display.set_mode(tamanhoTela)
	pygame.display.set_caption("Visualização de Resolução de EDO")

	passoAtual = 0
	
	"""newMoon = get_image("new_moon.png")
	fullMoon = get_image("full_moon.png")
	newMoon = pygame.transform.smoothscale(newMoon,(30,30))
	fullMoon = pygame.transform.smoothscale(fullMoon,(30,30))"""

	caixaSprite = get_image("caixa.png")
	caixaSprite = pygame.transform.smoothscale(caixaSprite,(30,30))
	caixa1 = Caixa(caixaSprite, animacao[0], tela)
	caixa2 = Caixa(caixaSprite, animacao[1], tela)



	mola1 = MolaVertical(0,caixa1.retangulo.top,5,tamanhoTela[0]/2,3,tela)
	mola2 = MolaVertical(caixa1.retangulo.bottom,caixa2.retangulo.top,5,tamanhoTela[0]/2,3,tela)

	print passo*10
	aberto = True
	relogio = pygame.time.Clock()
	while aberto:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				aberto = False
				break

		tela.fill(cores["BRANCO"])
		#criarLinhas(caixa1,caixa2,tela)
		mola1.desenharMola()
		mola2.desenharMola()
		caixa1.desenharProxPosicao()
		caixa2.desenharProxPosicao()
		mola1.yfinal = caixa1.retangulo.top
		mola2.yinicial = caixa1.retangulo.bottom
		mola2.yfinal = caixa2.retangulo.top

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
