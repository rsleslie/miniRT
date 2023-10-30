#miniRT - Meu Primeiro RayTracer com miniLibX

miniRT é um programa de renderização que permite criar imagens computadorizadas a partir de cenas definidas em um arquivo no formato .rt, ele renderiza cenas de objetos geometricos como esferas, cilindros e planos. 

A tecnica ultilizada é chamada de "Ray Tracer" que simula o comportamento da luz através de calculos matematicos em programação. O objetivo é tornar os reflexos, refrações e iluminações de gráficos 3D mais realistas

Funcionalidades

Renderização de cenas com objetos geométricos como esferas, cilindros e planos.
Implementação de iluminação ambiente e difusa.
Suporte para redirecionamento de saída.
Rastreamento de raios para simular reflexões e sombras.
Controle de câmeras para ajustar a perspectiva das cenas.
Interface gráfica para visualização das imagens renderizadas.

Pré-requisitos

GCC (GNU Compiler Collection)
miniLibX (biblioteca gráfica)

Como Usar

Clone este repositório:

~ bash

Copy code:

~ git clone https://github.com/rsleslie/miniRT.git

~cd miniRT

Compile o projeto:

~bash

Copy code

~ make

Execute o miniRT, fornecendo um arquivo de cena no formato .rt:

bash

Copy code

./miniRT ../aquivo3/{cena}.rt

As cenas estão no arquivo3
Aproveite a renderização das cenas e explore o mundo do Ray Tracing!
