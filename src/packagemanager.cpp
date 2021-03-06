#include "packagemanager.hpp"

//This is the constructor
void PackageManager::init(string pm) {
	
	if(pm == "apt-get") {
		//apt-get
		search = "apt-cache search ";
		install = "apt-get install ";
		remove = "apt-get remove ";
		autoremove = "apt-get autoremove";
		update = "apt-get update";
		upgrade = "apt-get upgrade";
		upgrade_pkg = "apt-get upgrade ";
		clean = "apt-get autoclean && apt-get clean";
	}

	else if(pm == "xbps") {
		//xbps
		search = "xbps-query -Rs ";
		install = "xbps-install ";
		remove = "xbps-remove ";
		autoremove = "xbps-remove -o";
		update = "xbps-install -S";
		upgrade = "xbps-install -Su";
		upgrade_pkg = "xbps-install -u ";
		clean = "xbps-remove -O";
	}

	else if(pm == "dnf") {
		//dnf
		search = "dnf search ";
		install = "dnf install ";
		remove = "dnf erase ";
		autoremove = "dnf autoremove";
		update = "dnf clean expire-cache && sudo dnf check-update";
		upgrade = "dnf update";
		upgrade_pkg = "dnf upgrade ";
		clean = "dnf clean all";
	}

	else if(pm == "yum") {
		//yum
		search = "yum search ";
		install = "yum install ";
		remove = "yum erase ";
		autoremove = "yum autoremove";
		update = "yum check-update";
		upgrade = "yum update";
		upgrade_pkg = "yum update ";
		clean = "yum clean all";
	}

	else if(pm == "zypper") {
		//zypper
		search = "zypper search ";
		install = "zypper install ";
		remove = "zypper remove ";
		autoremove = "zypper rm -u";
		update = "zypper refresh zypper ref";
		upgrade = "zypper up";
		upgrade_pkg = "zypper in ";
		clean = "zypper clean";
	}

	else if(pm == "eopkg") {
		//eopkg
		search = "eopkg search ";
		install = "eopkg install ";
		remove = "eopkg remove ";
		autoremove = "eopkg remove-orphans";
		update = "eopkg ur";
		upgrade = "eopkg upgrade";
		upgrade_pkg = "zypper in ";
		clean = "eopkg delete-cache";
	}

	else if(pm == "pacman") {
		//pacman
		search = "pacman -Ss ";
		install = "pacman -S ";
		remove = "pacman -Rs ";
		autoremove = "pacman -Rns $(pacman -Qtdq)";
		update = "pacman -Syy";
		upgrade = "pacman -Syu";
		upgrade_pkg = "pacman -S ";
		clean = "pacman -Sc";
	}

	else if(pm == "emerge") {
		//emerge / portage
		search = "emerge -S ";
		install = "emerge --ask ";
		remove = "emerge -C ";
		autoremove = "emerge --depclean -a";
		update = "layman -f";
		upgrade = "emerge --ask -u world && emerge --ask -uDN world";
		upgrade_pkg = "emerge -avDuN";
		clean = "eclean distfiles";
	}

	else if(pm == "pkg") {
		//pkg (FreeBSD)
		search = "pkg search ";
		install = "pkg install ";
		remove = "pkg delete ";
		autoremove = "pkg autoremove";
		update = "pkg update";
		upgrade = "pkg upgrade";
		upgrade_pkg = "pkg -f install ";
		clean = "pkg clean";
	}

	else if(pm == "chromebrew") {
		//chromebrew
		search = "crew search ";
		install = "crew install ";
		remove = "crew remove ";
		autoremove = "exit=Chromebrew does not support this";
		update = "exit=Chromebrew does not support this";
		upgrade = "crew upgrade";
		upgrade_pkg = "crew upgrade ";
		clean = "exit=Chromebrew does not support this";
	}

	else if(pm == "homebrew") {
		//homebrew
		search = "brew search ";
		install = "brew install ";
		remove = "brew uninstall ";
		autoremove = "exit=Homebrew does this automatically";
		update = "brew update";
		upgrade = "brew upgrade";
		upgrade_pkg = "brew upgrade ";
		clean = "exit=Homebrew does this automatically";
	}

	else if(pm == "nix") {
		//nix
		search = "nix search ";
		install = "nix-env -i ";
		remove = "nix-env -e ";
		autoremove = "nix-collect-garbage -d";
		update = "nix-channel --update nixpkgs";
		upgrade = "nix-env -u '*'";
		upgrade_pkg = "nix-env -u ";
		clean = "exit= ";
	}

	else if(pm == "snap") {
		//snap(d)
		search = "snap find ";
		install = "snap install ";
		remove = "snap remove ";
		autoremove = "exit=A snap doesn't have orphans";
		update = "exit=snapd does not support this, you may want to upgrade ?";
		upgrade = "snap refresh";
		upgrade_pkg = "snap refresh ";
		clean = "exit=snapd does this automatically after some time";
	}

	else if(pm == "npm") {
		//npm (Global)
		search = "npm search ";
		install = "npm install -g ";
		remove = "npm uninstall -g ";
		autoremove = "npm prune";
		update = "exit=npm does not support this, you may want to upgrade ?";
		upgrade = "npm update -g";
		upgrade_pkg = "npm update -g ";
		clean = "npm cache clean --force";
	}

	else if(pm == "flatpak") {
		//flatpak (You should checkout the README)
		search = "flatpak search ";
		install = "flatpak install ";
		remove = "flatpak uninstall ";
		autoremove = "exit=A flatpak does not have orphans";
		update = "exit=Flatpak does not support this, you may want to upgrade ?";
		upgrade = "flatpak update";
		upgrade_pkg = "flatpak update ";
		clean = "exit=flatpak does not support this";
	}


}