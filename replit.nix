{ pkgs }: {
	deps = [
		pkgs.sudo
  pkgs.run
  pkgs.aspell
    pkgs.aspellDicts.en
    pkgs.cmake
    pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
    pkgs.cmake
    pkgs.openssl
	];
}