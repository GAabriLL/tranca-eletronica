# Tranca Eletrônica com ESP32 e RFID

Este projeto implementa uma tranca eletrônica utilizando um ESP32, um leitor RFID MFRC522 e um motor de passo para acionamento. O sistema autentica usuários por meio de cartões RFID e controla o mecanismo de travamento com sensores de fim de curso para garantir precisão e segurança. Ideal para aplicações de controle de acesso inteligente.

<h2>Características</h2>
<ul>
    <li>Autenticação via RFID</li>
    <li>Controle de motor de passo</li>
    <li>Fim de curso para controle de posição</li>
    <li>Baseado em ESP32</li>
</ul>

<h2>Requisitos</h2>
<ul>
    <li>ESP32</li>
    <li>Leitor RFID MFRC522</li>
    <li>Motor de passo e driver compatível</li>
    <li>Bibliotecas: <code>SPI.h</code>, <code>MFRC522.h</code>, <code>AccelStepper.h</code></li>
</ul>

<h2>Instalação</h2>
<p>Clone este repositório e abra o código na IDE do Arduino:</p>
<pre><code>git clone https://github.com/seu-usuario/tranca-eletronica-esp32.git</code></pre>
<p>Faça o upload do código para o ESP32.</p>

<h2>Uso</h2>
<p>O sistema lê um cartão RFID e, se autorizado, aciona o motor de passo para destravar a fechadura. Após um tempo, a tranca é acionada novamente para fechar.</p>

<h2>Contribuição</h2>
<p>Contribuições são bem-vindas! Para contribuir:</p>
<ol>
    <li>Fork este repositório.</li>
    <li>Crie uma branch para sua feature (<code>git checkout -b minha-feature</code>).</li>
    <li>Commit suas mudanças (<code>git commit -m 'Minha nova feature'</code>).</li>
    <li>Envie para o repositório (<code>git push origin minha-feature</code>).</li>
    <li>Abra um Pull Request.</li>
</ol>
