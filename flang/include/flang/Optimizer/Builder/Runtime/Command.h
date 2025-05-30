//===-- Command.cpp -- generate command line runtime API calls ------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef FORTRAN_OPTIMIZER_BUILDER_RUNTIME_COMMAND_H
#define FORTRAN_OPTIMIZER_BUILDER_RUNTIME_COMMAND_H

namespace mlir {
class Value;
class Location;
} // namespace mlir

namespace fir {
class FirOpBuilder;
} // namespace fir

namespace fir::runtime {

/// Generate call to COMMAND_ARGUMENT_COUNT intrinsic runtime routine.
mlir::Value genCommandArgumentCount(fir::FirOpBuilder &, mlir::Location);

/// Generate a call to the GetCommand runtime function which implements the
/// GET_COMMAND intrinsic.
/// \p command, \p length and \p errmsg must be fir.box that can be absent (but
/// not null mlir values). The status value is returned.
mlir::Value genGetCommand(fir::FirOpBuilder &, mlir::Location,
                          mlir::Value command, mlir::Value length,
                          mlir::Value errmsg);

/// Generate a call to the GetPID runtime function which implements the
/// GETPID intrinsic.
mlir::Value genGetPID(fir::FirOpBuilder &, mlir::Location);

/// Generate a call to the GetCommandArgument runtime function which implements
/// the GET_COMMAND_ARGUMENT intrinsic.
/// \p value, \p length and \p errmsg must be fir.box that can be absent (but
/// not null mlir values). The status value is returned.
mlir::Value genGetCommandArgument(fir::FirOpBuilder &, mlir::Location,
                                  mlir::Value number, mlir::Value value,
                                  mlir::Value length, mlir::Value errmsg);

/// Generate a call to GetEnvVariable runtime function which implements
/// the GET_ENVIRONMENT_VARIABLE intrinsic.
/// \p value, \p length and \p errmsg must be fir.box that can be absent (but
/// not null mlir values). The status value is returned. \p name must be a
/// fir.box and \p trimName a boolean value.
mlir::Value genGetEnvVariable(fir::FirOpBuilder &, mlir::Location,
                              mlir::Value name, mlir::Value value,
                              mlir::Value length, mlir::Value trimName,
                              mlir::Value errmsg);

/// Generate a call to the GetCwd runtime function which implements
/// the GETCWD intrinsic.
mlir::Value genGetCwd(fir::FirOpBuilder &builder, mlir::Location loc,
                      mlir::Value c);

/// Generate a call to the Hostnm runtime function which implements
/// the HOSTNM intrinsic.
mlir::Value genHostnm(fir::FirOpBuilder &builder, mlir::Location loc,
                      mlir::Value res);

/// Generate a call to the Perror runtime function which implements
/// the PERROR GNU intrinsic.
void genPerror(fir::FirOpBuilder &builder, mlir::Location loc,
               mlir::Value string);

/// Generate a call to the runtime function which implements the PUTENV
/// intrinsic.
mlir::Value genPutEnv(fir::FirOpBuilder &builder, mlir::Location loc,
                      mlir::Value str, mlir::Value strLength);

/// Generate a call to the Unlink runtime function which implements
/// the UNLINK intrinsic.
mlir::Value genUnlink(fir::FirOpBuilder &builder, mlir::Location loc,
                      mlir::Value path, mlir::Value pathLength);

} // namespace fir::runtime
#endif // FORTRAN_OPTIMIZER_BUILDER_RUNTIME_COMMAND_H
