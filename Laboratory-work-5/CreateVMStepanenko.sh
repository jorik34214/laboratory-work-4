# 2.2.7 Зберегти всі команди керування віртуальною машиною, які було виконано у попередніх пунктах, у файлі CreateVMSurname.sh, де Surname – ваше прізвище транслітерацією, наприклад «CreateVMBlazhko.sh»;

VBoxManage createvm --name "Linux Of Stepanenko 2" --register

VBoxManage modifyvm "Linux Of Stepanenko 2" --memory 2422

VBoxManage modifyvm "Linux Of Stepanenko 2" \
--graphicscontroller=vboxvga --vram 128

VBoxManage modifyvm "Linux Of Stepanenko 2" --nic1 nat

VBoxManage storagectl "Linux Of Stepanenko 2" --name "StepanenkoSATA" \
--add sata --controller IntelAHCI

VBoxManage storagectl "Linux Of Stepanenko 2" --name "StepanenkoIDE" \
--add ide --controller PIIX4

VBoxManage createmedium --filename "DiskStepanenko.vdi" --size 9640

VBoxManage storageattach "Linux Of Stepanenko 2" \
--storagectl "StepanenkoSATA" --port 0 --device 0 --type hdd \
--medium "DiskStepanenko.vdi"

VBoxManage storageattach "Linux Of Stepanenko 2" \
--storagectl "StepanenkoIDE" --port 0 --device 0 --type dvddrive \
--medium "C:\Users\kaban\Downloads\ubuntu-14.04.6-server-amd64.iso"

VBoxManage startvm "Linux Of Stepanenko 2"

VBoxManage controlvm "Linux Of Stepanenko 2" poweroff

VBoxManage unregistervm "Linux Of Stepanenko 2" --delete --delete-all
