import pygame

class Massa():
	def __init__(self,largura,altura,cor,animacao,tela):
		self.largura = largura
		self.altura = altura
		self.cor = cor
		
		self.animacao = animacao
		self.tela = tela

		self.posicaoAtual = 0
		self.offsetX = tela.get_width() / 2

	def desenharPosicao(self,posicaoAnimacao):
		posx, posy = self.animacao[posicaoAnimacao]
		pygame.draw.rect(self.tela, self.cor, (posx+self.offsetX, posy, self.largura, self.altura), 0)
		
	def desenharProxPosicao(self):
		self.desenharPosicao(self.posicaoAtual)
		self.posicaoAtual = (self.posicaoAtual + 1)%len(self.animacao) 