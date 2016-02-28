# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure(2) do |config|
  config.vm.box = "puphpet/ubuntu1404-x64"

#  config.vm.synced_folder ".", "/vagrant", type: "rsync",
#    rsync__exclude: [".git/", '.idea/', 'php/']

  config.vm.synced_folder ".", "/vagrant", type: "nfs", mount_options: ['rw', 'vers=3', 'tcp', 'fsc', 'actimeo=2']

end
