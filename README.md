# conan-dependency-error

Executing the following commands results in a missing prebuilt package.
I've used artifactory as described [here](https://docs.conan.io/2/tutorial/conan_repositories/setting_up_conan_remotes/artifactory/artifactory_ce_cpp.html).

```sh
cd a
conan create .
conan upload "aa" -r=artifactory
cd ../b
conan create .
conan upload "bb" -r=artifactory
cd ../c
conan create .
conan upload "cc" -r=artifactory
```

Go into `a/conanfile.py` and modify version from **0.0.0.1** to **0.1.0.0**

```sh
cd ../a
conan create .
conan upload "aa" -r=artifactory
conan remove "*" -c
cd ../c
conan create .
```

Following error occurs:
```sh
======== Exporting recipe to the cache ========
cc/0.0.0.1: Exporting package recipe: /home/christian/conanPackages/conan-dependency-error/c/conanfile.py
cc/0.0.0.1: Copied 1 '.py' file: conanfile.py
cc/0.0.0.1: Copied 1 '.txt' file: CMakeLists.txt
cc/0.0.0.1: Copied 1 '.h' file: c.h
cc/0.0.0.1: Copied 1 '.cpp' file: c.cpp
cc/0.0.0.1: Exported to cache folder: /home/christian/.conan2/p/ccf48f86b7707a9/e
cc/0.0.0.1: Exported: cc/0.0.0.1#926542d91693d61e282c5eca9319f597 (2024-04-06 14:42:34 UTC)

======== Input profiles ========
Profile host:
[settings]
arch=x86_64
build_type=Release
compiler=gcc
compiler.cppstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=12
os=Linux

Profile build:
[settings]
arch=x86_64
build_type=Release
compiler=gcc
compiler.cppstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=12
os=Linux


======== Computing dependency graph ========
aa/0.1.0.0: Not found in local cache, looking in remotes...
aa/0.1.0.0: Checking remote: conancenter
aa/0.1.0.0: Checking remote: artifactory
aa/0.1.0.0: Downloaded recipe revision 29ce3a046b2b740dfcac6e1ffe615f9e
bb/0.0.0.1: Not found in local cache, looking in remotes...
bb/0.0.0.1: Checking remote: conancenter
bb/0.0.0.1: Checking remote: artifactory
bb/0.0.0.1: Downloaded recipe revision 554f227c8f1d1674e37c9126afd8fe1a
Graph root
    cli
Requirements
    aa/0.1.0.0#29ce3a046b2b740dfcac6e1ffe615f9e - Downloaded (artifactory)
    bb/0.0.0.1#554f227c8f1d1674e37c9126afd8fe1a - Downloaded (artifactory)
    cc/0.0.0.1#926542d91693d61e282c5eca9319f597 - Cache
Resolved version ranges
    aa/[~0]: aa/0.1.0.0
    bb/[~0]: bb/0.0.0.1

======== Computing necessary packages ========
bb/0.0.0.1: Checking 11 compatible configurations:
bb/0.0.0.1: 'a6c73cc7b792354d86cfbae00f1687850024588e': compiler.cppstd=98
bb/0.0.0.1: '5984b6ebdd9d7ed2952ba81774df19f78df83b85': compiler.cppstd=gnu98
bb/0.0.0.1: '9025e41836454d0edcd1c8511f82bbd3255f106c': compiler.cppstd=11
bb/0.0.0.1: 'ca67775e40e5f85ad1aab7eceb072efe626ae373': compiler.cppstd=gnu11
bb/0.0.0.1: '36dedb54da0c335f7cc0cff27698112f985e6ae6': compiler.cppstd=14
bb/0.0.0.1: '4d89409e77b31ec7ab2b5ac4689fbc03bd5c392b': compiler.cppstd=gnu14
bb/0.0.0.1: '9139cd55249bc4c40a1113d6fa8d5db0ec0a9d07': compiler.cppstd=17
bb/0.0.0.1: '1e0aedf3e3a17fb11a97718af92534e67c1cac24': compiler.cppstd=20
bb/0.0.0.1: '1d55ae962ca4286a30f005e9889bc2acaf67c1f9': compiler.cppstd=gnu20
bb/0.0.0.1: 'df0fe15e8e49e9d0c6b6becad0e9f661414a790a': compiler.cppstd=23
bb/0.0.0.1: 'ccf8ad2c6ef5513732377429ea9a511859b5246a': compiler.cppstd=gnu23
cc/0.0.0.1: Forced build from source
Requirements
    aa/0.1.0.0#29ce3a046b2b740dfcac6e1ffe615f9e:2b3e00e93be912c4468bf5911338440f07c9b5ac#ddc87bf0a3d37ba39779a29674f46bd9 - Download (artifactory)
    bb/0.0.0.1#554f227c8f1d1674e37c9126afd8fe1a:97bfbf0aa35094df2bb0b3e26cdba7bf971b396e - Missing
    cc/0.0.0.1#926542d91693d61e282c5eca9319f597:74c6a3d4684b9824c110fb729b11e8e1287180a8 - Build

======== Installing packages ========
ERROR: Missing binary: bb/0.0.0.1:97bfbf0aa35094df2bb0b3e26cdba7bf971b396e

bb/0.0.0.1: WARN: Can't find a 'bb/0.0.0.1' package binary '97bfbf0aa35094df2bb0b3e26cdba7bf971b396e' for the configuration:
[settings]
arch=x86_64
build_type=Release
compiler=gcc
compiler.cppstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=12
os=Linux
[options]
fPIC=True
shared=False
[requires]
aa/0.1.Z

ERROR: Missing prebuilt package for 'bb/0.0.0.1'
Check the available packages using 'conan list bb/0.0.0.1:* -r=remote'
or try to build locally from sources using the '--build=bb/0.0.0.1' argument

More Info at 'https://docs.conan.io/2/knowledge/faq.html#error-missing-prebuilt-package'
```
