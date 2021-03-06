from enigma.machine import EnigmaMachine

machine = EnigmaMachine.from_key_sheet(
       rotors='I II III',
       reflector='B',
       ring_settings=[0, 0, 0],
       plugboard_settings='')

# set machine initial starting position
machine.set_display('AAA')

# decrypt the message key
msg_key = machine.process_text('KCH')

# decrypt the cipher text with the unencrypted message key
machine.set_display(msg_key)

ciphertext = 'NIBLFMYMLLUFWCASCSSNVHAZ'
plaintext = machine.process_text(ciphertext)

print(plaintext)
