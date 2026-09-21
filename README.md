# Switch-Tester-Jig
Created a switch testing jig using Arduino UNO which tests the electrical durability of contact in scooty switches. 
<br><br>
This is a project that I created during my internship in a 2 wheeler EV startup company. The handle-bar switch assembly are fitted by various switches that the company imports from different vendors. Since it's a startup company we experimented by ordering from different vendors for the same switch. This project was made to test the durability of those.
<br><br>
The various types of switches that were tested are: Horn, Upper-Dipper, Ignition, Reverse.
<br>
Components used: A switch and motor holder,L298N motor controller, two 16X2 I2C LCD, arduino uno, jumper cables,cam to press the button, Switch coupler,12v battery to run motor, Switch for manual control.
<br>
The cam and holder for switches was made by senior.
<br><br>
<table>
  <tr>
    <td><img width="400" height="400" alt="jig" src="https://github.com/user-attachments/assets/ece7263d-2293-4c04-96ea-a8c1ee0781ca" />
    <br>  <div  align="center"><sub><i> Fig1:Jig with cam and switch installed</i></sub></div>
</td>
    <td><img width="500" height="400" alt="motor holder" src="https://github.com/user-attachments/assets/9f8f8aad-7090-4424-aada-62776bd32910" />
    <br>  <div  align="center"><sub><i> Fig2:motor fitting location</i></sub></div>
</td>
    <td><img width="400" height="400" alt="jig switch coupler" src="https://github.com/user-attachments/assets/e6d3a487-ca5c-4368-8fbd-3488ecc84802" />
    <br><div align="center"><sub><i> Fig3:back side</i></sub></div>
</td>
  </tr>
</table>
<br><br>
<table>
  <tr>
    <td><img width="400" height="400" alt="arduino" src="https://github.com/user-attachments/assets/46fd0736-bebe-4e4c-976e-e64e37db496b" />
    <br>  <div  align="center"><sub><i> Fig4:Arduino UNO</i></sub></div>
</td>
    <td><img width="500" height="500" alt="2 lcds" src="https://github.com/user-attachments/assets/a2e2f4ca-0aee-41ff-b05a-5e63d09539ad" />
    <br>  <div  align="center"><sub><i> Fig5:2 LCDs</i></sub></div>
</td>
    <td><img width="500" height="400" alt="battery and switch" src="https://github.com/user-attachments/assets/4a310bf0-a8d6-4d88-826e-e37956856421" />
    <br><div align="center"><sub><i> Fig6:12v Battery & ON-OFF Switch for manual control</i></sub></div>
</td>
  </tr>
</table>
<br>
<table>
  <tr>
    <td><img width="500" height="500" alt="L298N motor controller" src="https://github.com/user-attachments/assets/252934df-8c96-401d-9e7d-405b1d424fcd" />
    <br>  <div  align="center"><sub><i> Fig7:Arduino UNO</i></sub></div>
</td>
    <td><img width="340" height="262" alt="switches" src="https://github.com/user-attachments/assets/c67eb4f6-06e2-45d1-8c24-6db407ee5143" />
    <br>  <div  align="center"><sub><i> Fig8:Switches</i></sub></div>
</td>
    <td><img width="500" height="500" alt="12v motor" src="https://github.com/user-attachments/assets/11f03ef8-2c2f-4c2d-9bdb-501b3e07719c" />
    <br><div align="center"><sub><i> Fig9:12v DC Motor</i></sub></div>
</td>
  </tr>
</table>
<br>
<table>
  <tr>
    <td><img width="845" height="848" alt="Switch Pinout" src="https://github.com/user-attachments/assets/3e6ceb61-fba7-4cbc-924d-9d2f9e7374a9" />
    <br>  <div  align="center"><sub><i> Fig10:Switch Pinout</i></sub></div>
</td>
    <td><img width="1032" height="1390" alt="overall setup" src="https://github.com/user-attachments/assets/d12b4174-496a-42a5-a301-11c52287a0fe" />
    <br>  <div  align="center"><sub><i> Fig11:Overall Setup</i></sub></div>
</td>
  </tr>
</table>
<br><br>
Drive link for working video: https://drive.google.com/drive/folders/12oiliMJjxmbsB1hyvkpnEl2Vyk8v8IB5?usp=sharing
<br><br>
<table>
  <tr>
    <td>
    <td><img width="1920" height="1080" alt="Sch ERC check" src="https://github.com/user-attachments/assets/d3f0a813-ea32-4a3a-9abd-11ad30c4deea" />
  <br>  <div  align="center"><sub><i> Fig12:Schematic with ERC</i></sub></div>
</td>
    <td><img width="1920" height="1080" alt="DRC PCB editor Switch Test Jig" src="https://github.com/user-attachments/assets/cad6b007-41d1-47ff-b016-fb7a3e25bc1a" />
    <br>  <div  align="center"><sub><i> Fig13:PCB editor DRC check</i></sub></div>
</td>
    <td><img width="1920" height="1080" alt="Switch Test Jig PCB editor" src="https://github.com/user-attachments/assets/73f8d65e-6681-4380-b0a1-04810e22b2d8" />
    <br>  <div  align="center"><sub><i> Fig14:PCB editor Full view</i></sub></div>
</td>
  </tr>
</table>
<br>
<table>
  <tr>
    <td><img width="600" height="500" alt="3d front switch test" src="https://github.com/user-attachments/assets/d40f02a0-5478-4369-9f54-e12b53090642" />
  <br>  <div  align="center"><sub><i> Fig15:3D Front</i></sub></div>
</td>
    <td><img width="600" height="500" alt="3d side switch test" src="https://github.com/user-attachments/assets/b63b57ec-ada1-4a7a-83af-2d27b660141e" />
    <br>  <div  align="center"><sub><i> Fig16:3D Side</i></sub></div>
</td>
    <td><img width="600" height="500" alt="3d back switch test" src="https://github.com/user-attachments/assets/8ccc5ccd-733a-4eed-9e24-a15e96998fef" />
    <br>  <div  align="center"><sub><i> Fig17:3D Back</i></sub></div>
</td>
  </tr>
</table>
