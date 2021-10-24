# Maintainer: Daniil Gentili <daniil@daniil.it>

_repouser=danog
_reponame=PrimeModule-ext

pkgname=primemodule
pkgdesc="C++ header-only library, binary and FFI library for factorizing huge (up to 2^63-1) numbers (optimized for huge semiprimes)."
pkgver=1.0.0
pkgrel=1
arch=('any')
license=('GPL')

source=("https://github.com/$_repouser/$_reponame/archive/refs/tags/${pkgver}.tar.gz")
sha512sums=('0dc46842c27c4cec27304998a55969093f04903f2bad182e88d5d783a4c4065290d5f0f49e6caec7eaae4c6e50a28c6d6e8e344ab17c655c4839d64bc55389db')

build() {
  cd "${srcdir}/${_reponame}-${pkgver}"

  make
}

package() {
  cd "${srcdir}/${_reponame}-${pkgver}"
  
  make DESTDIR="${pkgdir}/usr" install
}
