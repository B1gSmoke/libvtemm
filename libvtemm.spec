Name:           libvtemm12
Version:        0.20.6
Release:        1%{?dist}

Summary:        C++ interface for VTE (a GTK2 terminal emulator widget)

Group:          System Environment/Libraries
License:        LGPLv3+
URL:            http://gtkmm.sourceforge.net/
Source0:        http://ftp.gnome.org/pub/GNOME/sources/libvtemm/0.20/libvtemm-%{version}.tar.bz2
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires:  libsigc++20-devel >= 2.2.3
BuildRequires:  glibmm24-devel >= 2.21.3
BuildRequires:  pangomm-devel >= 2.24.0
BuildRequires:  gtkmm24-devel >= 2.17.2
BuildRequires:  vte-devel >= 0.20.5


%description
libvtemm provides a C++ interface to the VTE library.


%package        devel
Summary:        Headers for developing programs that will use %{name}.
Group:          Development/Libraries
Requires:       %{name} = %{version}-%{release}
Requires:       gtkmm24-devel
Requires:       vte-devel


%description devel
This package contains the static libraries and header files needed for
developing gtkmm applications.


%package        docs
Summary:        Documentation for %{name}, includes full API docs
Group:          Documentation
Requires:       %{name}-devel = %{version}-%{release}


%description    docs
This package contains the full API documentation for %{name}.


%prep
%setup -q -n libvtemm-%{version}


%build
%configure
make %{?_smp_mflags}


%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT
find $RPM_BUILD_ROOT -type f -name "*.la" -exec rm -f {} ';'

# Fix documentation installation, put everything under gtk-doc
mkdir -p ${RPM_BUILD_ROOT}%{_datadir}/gtk-doc/html/libvtemm-1.2
mv ${RPM_BUILD_ROOT}%{_docdir}/libvtemm-1.2/* ${RPM_BUILD_ROOT}%{_datadir}/gtk-doc/html/libvtemm-1.2/
mv ${RPM_BUILD_ROOT}%{_datadir}/devhelp/books/libvtemm-1.2/*.devhelp ${RPM_BUILD_ROOT}%{_datadir}/gtk-doc/html/libvtemm-1.2
sed -i 's:../../../doc/libvtemm-1.2/docs/:docs/:' ${RPM_BUILD_ROOT}%{_datadir}/gtk-doc/html/libvtemm-1.2/*.devhelp
rm -r ${RPM_BUILD_ROOT}%{_docdir}/libvtemm-1.2


%clean
rm -rf $RPM_BUILD_ROOT


%post -p /sbin/ldconfig


%postun -p /sbin/ldconfig


%files
%defattr(-, root, root, -)
%doc AUTHORS ChangeLog COPYING NEWS README
%{_libdir}/*.so.*


%files devel
%defattr(-, root, root, -)
%{_includedir}/libvtemm-1.2
%{_libdir}/*.so
%{_libdir}/libvtemm-1.2
%{_libdir}/pkgconfig/*.pc


%files docs
%defattr(-, root, root, -)
%doc %{_datadir}/gtk-doc/html/libvtemm-1.2


%changelog
* Tue Aug 25 2009 Krzesimir Nowak <qdlacz@gmail.com> - 0.20.4-1
- Initial release of libvtemm-1.2
