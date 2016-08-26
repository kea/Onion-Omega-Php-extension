# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure(2) do |config|
  config.vm.box = "puphpet/ubuntu1404-x64"

  config.vm.synced_folder ".", "/vagrant", type: "nfs", mount_options: ['rw', 'vers=3', 'tcp', 'fsc', 'actimeo=2']

  config.vm.provider "vmware_fusion" do |v|
    v.vmx["memsize"] = 2048
    v.vmx["numvcpus"] = 4
  end
end
