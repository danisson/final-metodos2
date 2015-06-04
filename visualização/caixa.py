import pygame

class Caixa():
	def __init__(self,caixaSprite,animacao,tela):
		self.largura = caixaSprite.get_width()
		self.altura = caixaSprite.get_height()
		self.caixaSprite = caixaSprite
		
		self.animacao = animacao
		self.tela = tela

		self.posicaoAtual = 0
		self.offsetX = tela.get_width() / 2
		
		self.retangulo = pygame.Rect(animacao[self.posicaoAtual][0]-self.largura/2+self.offsetX,animacao[self.posicaoAtual][1]+self.altura/2,self.largura,self.altura)		
		
		
	def desenharProxPosicao(self):
		self.tela.blit(self.caixaSprite,self.retangulo)		
		self.posicaoAtual = (self.posicaoAtual + 1)%len(self.animacao)		
		self.retangulo.x, self.retangulo.y = (self.animacao[self.posicaoAtual][0]+self.offsetX-self.largura/2,self.animacao[self.posicaoAtual][1]+self.altura/2)
		print str(self.retangulo.x) + " " + str(self.retangulo.y)
